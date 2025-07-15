// attributes: thunk
int __stdcall __WSAFDIsSet(SOCKET fd, fd_set *a2)
{
  int v3; // [esp+Ch] [ebp+Ch]
  int v4; // [esp+10h] [ebp+10h]
  int v5; // [esp+14h] [ebp+14h]

  return ((int (__stdcall *)(SOCKET, fd_set *, int, int, int))(&off_8E3A98 + 7))(fd, a2, v3, v4, v5);
}
