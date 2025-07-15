int __thiscall Scaleform::String::GetLength(Scaleform::String *this)
{
  unsigned int v1; // esi
  int v2; // edi
  int result; // eax

  v1 = this->HeapTypeBits & 0xFFFFFFFC;
  v2 = *(_DWORD *)v1 & 0x7FFFFFFF;
  if ( *(int *)v1 < 0 )
    return *(_DWORD *)v1 & 0x7FFFFFFF;
  result = Scaleform::UTF8Util::GetLength((char *)(v1 + 8), *(_DWORD *)v1 & 0x7FFFFFFF);
  if ( result == v2 )
    *(_DWORD *)v1 |= 0x80000000;
  return result;
}
