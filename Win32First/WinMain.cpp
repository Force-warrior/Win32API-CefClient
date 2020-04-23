#include <windows.h>


#define MAX_LOADSTRING 100

// 全局变量:
HINSTANCE hInst;                                // 当前实例
WCHAR szTitle[MAX_LOADSTRING];                  // 标题栏文本
//WCHAR szWindowClass[MAX_LOADSTRING];            // 主窗口类名

static WCHAR szWindowClass[] = TEXT("windosClssName");

// 此代码模块中包含的函数的前向声明:
BOOL                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

//HINSTANCE  程序实例句柄   

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	MSG msg;
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	BOOL ret = MyRegisterClass(hInstance);

	InitInstance(hInstance, nCmdShow);

	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}

BOOL MyRegisterClass(HINSTANCE hInstance){
	
	WNDCLASS wndClass;
	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndClass.hCursor = LoadCursor(NULL, IDC_CROSS);
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndClass.hInstance = hInstance;
	wndClass.lpfnWndProc = WndProc;
	wndClass.lpszClassName = szWindowClass;
	wndClass.lpszMenuName = NULL;
	wndClass.style = WS_OVERLAPPED;

	return RegisterClass(&wndClass);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow) {
	hInst = hInstance;
	HWND hWnd = CreateWindow(szWindowClass, TEXT(""), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInst, NULL);
	if (!hWnd)
		return FALSE;
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam){
	
	switch (message)
	{
		case WM_PAINT:
		{
	
		}break;
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
			break;
		}

	return 0;
}