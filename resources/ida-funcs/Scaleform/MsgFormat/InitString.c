void __thiscall Scaleform::MsgFormat::InitString(Scaleform::MsgFormat *this, char *pbuffer, unsigned int size)
{
  unsigned int v5; // edx
  int v6; // ebx
  char *v7; // ecx
  char *v8; // eax
  int v9; // eax
  int v10; // ecx
  unsigned int v11; // esi
  unsigned int v12; // [esp+8h] [ebp-Ch]
  const __m128i *v13; // [esp+Ch] [ebp-8h] BYREF
  unsigned int v14; // [esp+10h] [ebp-4h]
  unsigned int v15; // [esp+1Ch] [ebp+8h]

  v5 = 0;
  v12 = this->Data.Size;
  v15 = 0;
  if ( size )
  {
    v6 = 0;
    do
    {
      if ( v5 >= v12 )
        return;
      if ( v5 >= 0x10 )
        v7 = (char *)&this->Data.DynamicArray.Data.Data[v6 - 16];
      else
        v7 = &this->Data.StaticArray[v6 * 12];
      if ( v5 >= 0x10 )
        v8 = (char *)&this->Data.DynamicArray.Data.Data[v6 - 16];
      else
        v8 = &this->Data.StaticArray[v6 * 12];
      v9 = *(_DWORD *)v8;
      if ( v9 )
      {
        if ( v9 != 2 )
          goto LABEL_20;
        v10 = *((_DWORD *)v7 + 1);
        if ( !v10 )
          goto LABEL_20;
        (*(void (__thiscall **)(int, const __m128i **))(*(_DWORD *)v10 + 16))(v10, &v13);
        v11 = v14;
        if ( size < v14 )
          v11 = size;
        memcpy((int)pbuffer, v13, v11);
      }
      else
      {
        v11 = (unsigned __int8)v7[8];
        if ( size < v11 )
          v11 = size;
        memcpy((int)pbuffer, *((const __m128i **)v7 + 1), v11);
      }
      v5 = v15;
      size -= v11;
      pbuffer += v11;
LABEL_20:
      ++v5;
      ++v6;
      v15 = v5;
    }
    while ( size );
  }
}
