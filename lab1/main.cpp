#include <QCoreApplication>
#include <windows.h>
#include <sysinfoapi.h>

extern "C" __declspec(dllimport)
BOOL __stdcall GetPhysicallyInstalledSystemMemory(PULONGLONG);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    SYSTEM_INFO siSysInfo;
    GetSystemInfo(&siSysInfo);
    printf("Hardware information: \n");
    printf("  Processor Architecture: %u\n", siSysInfo.wProcessorArchitecture);
    printf("  Number of processors: %u\n", siSysInfo.dwNumberOfProcessors);
    printf("  Page size: %u\n", siSysInfo.dwPageSize);
    printf("  Processor Level: %u\n", siSysInfo.wProcessorLevel);
    printf("  Processor Revision: %u\n", siSysInfo.wProcessorRevision);
    printf("  Minimum application address: %lx\n", siSysInfo.lpMinimumApplicationAddress);
    printf("  Maximum application address: %lx\n", siSysInfo.lpMaximumApplicationAddress);
    printf("  Active processor mask: %u\n", siSysInfo.dwActiveProcessorMask);

    ULONGLONG memInfo;
    GetPhysicallyInstalledSystemMemory(&memInfo);
    printf("  RAM size: %u\n", memInfo);

    return a.exec();
}
