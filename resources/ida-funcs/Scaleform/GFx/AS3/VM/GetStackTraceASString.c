void __thiscall Scaleform::GFx::AS3::VM::GetStackTraceASString(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::ASString *result,
        const __m128i *line_pref)
{
  unsigned int Size; // eax
  unsigned int v4; // eax
  Scaleform::GFx::AS3::CallFrame *v5; // edi
  Scaleform::GFx::ASStringNode *v6; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  void *v8; // edi
  Scaleform::GFx::ASStringNode *pObject; // [esp+0h] [ebp-328h] BYREF
  unsigned int v10; // [esp+4h] [ebp-324h]
  unsigned int j; // [esp+8h] [ebp-320h]
  Scaleform::String v12; // [esp+Ch] [ebp-31Ch] BYREF
  Scaleform::GFx::ASString v13; // [esp+10h] [ebp-318h] BYREF
  unsigned int i; // [esp+14h] [ebp-314h]
  Scaleform::GFx::AS3::VM *v15; // [esp+18h] [ebp-310h]
  Scaleform::MsgFormat::Sink r; // [esp+1Ch] [ebp-30Ch] BYREF
  Scaleform::MsgFormat v17; // [esp+28h] [ebp-300h] BYREF

  Size = this->CallStack.Size;
  v15 = this;
  i = Size;
  j = 0;
  if ( Size )
  {
    v4 = Size - 1;
    v10 = v4;
    while ( 1 )
    {
      v5 = &this->CallStack.Pages[v4 >> 6][v4 & 0x3F];
      if ( j )
        Scaleform::GFx::ASString::Append(result, (const __m128i *)"\n", (Scaleform::GFx::ASStringNode *)1);
      Scaleform::GFx::ASString::Append(result, line_pref, (Scaleform::GFx::ASStringNode *)strlen(line_pref->m128i_i8));
      Scaleform::GFx::ASString::Append(result, (const __m128i *)"at ", (Scaleform::GFx::ASStringNode *)3);
      pObject = v5->Name.pObject;
      ++pObject->RefCount;
      Scaleform::GFx::ASString::Append(result, (Scaleform::GFx::ASStringNode *)&pObject);
      v6 = pObject;
      --pObject->RefCount;
      if ( !v6->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v6);
      Scaleform::GFx::ASString::Append(result, (const __m128i *)"()", (Scaleform::GFx::ASStringNode *)2);
      if ( v5->CurrFileInd )
      {
        Scaleform::GFx::ASString::Append(result, (const __m128i *)"[", (Scaleform::GFx::ASStringNode *)1);
        Scaleform::GFx::AS3::VMFile::GetInternedString(v5->pFile, &v13, (Scaleform::GFx::ASStringNode *)v5->CurrFileInd);
        Scaleform::GFx::ASString::Append(result, (Scaleform::GFx::ASStringNode *)&v13);
        pNode = v13.pNode;
        --v13.pNode->RefCount;
        if ( !pNode->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
        Scaleform::GFx::ASString::Append(result, (const __m128i *)":", (Scaleform::GFx::ASStringNode *)1);
        pObject = (Scaleform::GFx::ASStringNode *)v5->CurrLineNumber;
        Scaleform::String::String(&v12);
        r.Type = tStr;
        r.SinkData.pStr = &v12;
        Scaleform::MsgFormat::MsgFormat(&v17, &r);
        Scaleform::MsgFormat::Parse(&v17, "{0}");
        Scaleform::MsgFormat::FormatD1<unsigned int>(&v17, (unsigned int *)&pObject);
        Scaleform::MsgFormat::FinishFormatD(&v17);
        Scaleform::MsgFormat::~MsgFormat(&v17);
        Scaleform::GFx::ASString::Append(
          result,
          (const __m128i *)((v12.HeapTypeBits & 0xFFFFFFFC) + 8),
          (Scaleform::GFx::ASStringNode *)((v12.HeapTypeBits & 0xFFFFFFFC)
                                         + 8
                                         + strlen((const char *)((v12.HeapTypeBits & 0xFFFFFFFC) + 8))
                                         + 1
                                         - ((v12.HeapTypeBits & 0xFFFFFFFC)
                                          + 9)));
        v8 = (void *)(v12.HeapTypeBits & 0xFFFFFFFC);
        if ( InterlockedExchangeAdd((volatile LONG *)((v12.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v8);
        Scaleform::GFx::ASString::Append(result, (const __m128i *)"]", (Scaleform::GFx::ASStringNode *)1);
      }
      --v10;
      ++j;
      if ( !--i )
        break;
      v4 = v10;
      this = v15;
    }
  }
}
