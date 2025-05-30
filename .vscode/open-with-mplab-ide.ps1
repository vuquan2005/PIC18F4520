param (
    [string]$projectFile = "" # Tham số cho file dự án
)
# Đường dẫn đến file thực thi của MPLab IDE
$mplabidePath = "C:\Program Files (x86)\Microchip\MPLAB IDE\Core\MPLAB.exe"

# Kiểm tra xem MPLab IDE có tồn tại không
if (-Not (Test-Path $mplabidePath)) {
    Write-Host "MPLab IDE is not found at: $mplabidePath" -ForegroundColor Red
    exit 1
}

# Thử mở MPLab IDE với file dự án
try {
    Start-Process $mplabidePath -ArgumentList "`"$projectFile`"" -ErrorAction Stop
    Write-Host "MPLab IDE opened successfully with file: $projectFile" -ForegroundColor Green
}
catch {
    if ($_.Exception -is [System.InvalidOperationException]) {
        Write-Host "User refused to open MPLab IDE (UAC disabled,...)." -ForegroundColor Red
    } else {
        Write-Host "Error when opening MPLab IDE: $($_.Exception.Message)" -ForegroundColor Red
    }
}