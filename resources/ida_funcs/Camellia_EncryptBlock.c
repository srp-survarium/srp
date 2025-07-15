unsigned __int32 __cdecl Camellia_EncryptBlock(unsigned int a1, int a2, int a3, unsigned __int32 *a4)
{
  return Camellia_EncryptBlock_Rounds((a1 > 0x80) + 3, a2, a3, a4);
}
