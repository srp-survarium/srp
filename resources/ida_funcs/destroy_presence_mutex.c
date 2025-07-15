void __cdecl destroy_presence_mutex()
{
  CloseHandle(s_presence_mutex);
}
