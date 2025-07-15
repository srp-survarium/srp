void __thiscall Scaleform::MsgFormat::MakeString(Scaleform::MsgFormat *this)
{
  unsigned int Size; // eax
  int v3; // ebx
  unsigned int v4; // edi
  char *v5; // ebp
  char *v6; // eax
  int v7; // eax
  int v8; // ecx
  Scaleform::MsgFormat::Sink::DataType Type; // eax
  __int32 v10; // eax
  char *pStr; // edi
  unsigned int StrSize; // eax
  unsigned int v13; // esi
  Scaleform::StringBuffer *pStrBuffer; // ebp
  unsigned int v15; // edi
  unsigned int v16; // ebx
  int v17; // edi
  char *v18; // ecx
  char *v19; // eax
  int v20; // eax
  int v21; // ecx
  unsigned int i; // [esp+10h] [ebp-Ch]
  unsigned int v23; // [esp+10h] [ebp-Ch]
  const __m128i *v24[2]; // [esp+14h] [ebp-8h] BYREF

  Size = this->Data.Size;
  v3 = 0;
  v4 = 0;
  this->StrSize = 0;
  for ( i = Size; v4 < i; ++v3 )
  {
    if ( v4 >= 0x10 )
      v5 = (char *)&this->Data.DynamicArray.Data.Data[v3 - 16];
    else
      v5 = &this->Data.StaticArray[v3 * 12];
    if ( v4 >= 0x10 )
      v6 = (char *)&this->Data.DynamicArray.Data.Data[v3 - 16];
    else
      v6 = &this->Data.StaticArray[v3 * 12];
    v7 = *(_DWORD *)v6;
    if ( v7 )
    {
      if ( v7 == 2 )
      {
        Scaleform::MsgFormat::Evaluate(this, v4);
        v8 = *((_DWORD *)v5 + 1);
        if ( v8 )
          this->StrSize += (*(int (__thiscall **)(int))(*(_DWORD *)v8 + 20))(v8);
      }
    }
    else
    {
      this->StrSize += (unsigned __int8)v5[8];
    }
    ++v4;
  }
  Type = this->Result.Type;
  if ( Type )
  {
    v10 = Type - 1;
    if ( v10 )
    {
      if ( v10 == 1 )
      {
        pStr = (char *)this->Result.SinkData.pStr;
        this->InitString(this, pStr, this->Result.SinkData.DataPtr.Size);
        StrSize = this->StrSize;
        v13 = this->Result.SinkData.DataPtr.Size - 1;
        if ( v13 < StrSize )
          StrSize = v13;
        pStr[StrSize] = 0;
      }
    }
    else
    {
      pStrBuffer = this->Result.SinkData.pStrBuffer;
      v15 = this->Data.Size;
      v23 = v15;
      Scaleform::StringBuffer::Reserve(pStrBuffer, this->StrSize + pStrBuffer->Size);
      v16 = 0;
      if ( v15 )
      {
        v17 = 0;
        do
        {
          if ( v16 >= 0x10 )
            v18 = (char *)&this->Data.DynamicArray.Data.Data[v17 - 16];
          else
            v18 = &this->Data.StaticArray[v17 * 12];
          if ( v16 >= 0x10 )
            v19 = (char *)&this->Data.DynamicArray.Data.Data[v17 - 16];
          else
            v19 = &this->Data.StaticArray[v17 * 12];
          v20 = *(_DWORD *)v19;
          if ( v20 )
          {
            if ( v20 == 2 )
            {
              v21 = *((_DWORD *)v18 + 1);
              if ( v21 )
              {
                (*(void (__thiscall **)(int, const __m128i **))(*(_DWORD *)v21 + 16))(v21, v24);
                Scaleform::StringBuffer::AppendString(pStrBuffer, v24[0], (unsigned int)v24[1]);
              }
            }
          }
          else
          {
            Scaleform::StringBuffer::AppendString(pStrBuffer, *((const __m128i **)v18 + 1), (unsigned __int8)v18[8]);
          }
          ++v16;
          ++v17;
        }
        while ( v16 < v23 );
      }
    }
  }
  else
  {
    Scaleform::String::AssignString(this->Result.SinkData.pStr, this, this->StrSize);
  }
}
