// FFI example
#ifdef _WIN32
    #include "windows.h"
#endif

var __FFI_SIMPLE_MSGBOX()
{
	#ifdef _WIN32
		int msgboxID = MessageBox(NULL, "A simple messagebox", "Nectar FFI", MB_YESNOCANCEL);
	#else 
		cout << "this platform is not compatible with MessageBox" << "\n";
	#endif
	return __NJS_VAR();
};

__NJS_FFI_FUNCTION(__WIN_MESSAGE_BOX, __NJS_VAR _message, __NJS_VAR _title)
{
	#ifdef _WIN32
		int msgboxID = MessageBox(NULL, __NJS_GET_STRING(_message), __NJS_GET_STRING(_title), MB_ICONWARNING | MB_YESNOCANCEL);
	#else 
		cout << "this platform is not compatible with MessageBox" << "\n";
	#endif
	return __NJS_VAR();
};
