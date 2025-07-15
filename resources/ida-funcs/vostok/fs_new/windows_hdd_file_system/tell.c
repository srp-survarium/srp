unsigned int __thiscall vostok::fs_new::windows_hdd_file_system::tell(
        vostok::fs_new::windows_hdd_file_system *this,
        HANDLE handle)
{
  unsigned int result; // eax
  _LARGE_INTEGER NewFilePointer; // [esp+0h] [ebp-8h] BYREF

  result = SetFilePointerEx(handle, 0, &NewFilePointer, 1u);
  if ( result )
    return NewFilePointer.LowPart;
  return result;
}
