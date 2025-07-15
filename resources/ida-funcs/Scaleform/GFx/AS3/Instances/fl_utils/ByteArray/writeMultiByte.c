void __thiscall Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::writeMultiByte(
        Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *this,
        const Scaleform::GFx::AS3::Value *result,
        const Scaleform::GFx::ASString *value,
        const Scaleform::GFx::ASString *charSet)
{
  const char *v5; // ecx
  int v6; // esi
  const char *v7; // ecx
  int v8; // esi
  unsigned int Size; // esi
  unsigned int Position; // edx
  const __m128i *pData; // edi
  unsigned int v12; // eax
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v14; // eax
  Scaleform::GFx::ASStringNode *v15; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  unsigned int v17; // edx
  unsigned int v18; // ebp
  unsigned int v19; // esi
  unsigned int Length; // ebx
  _DWORD *v21; // edi
  Scaleform::GFx::AS3::VM::ErrorID ID; // edi
  Scaleform::StringDataPtr v23; // [esp-8h] [ebp-30h]
  Scaleform::GFx::AS3::VM::Error v24; // [esp+10h] [ebp-18h] BYREF
  Scaleform::WStringBuffer wbuff; // [esp+18h] [ebp-10h] BYREF
  const __m128i *valuea; // [esp+30h] [ebp+8h]

  v5 = Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::UTF8_Names[0];
  v6 = 0;
  v24.ID = (Scaleform::GFx::AS3::VM::ErrorID)this;
  if ( Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::UTF8_Names[0] )
  {
    while ( strcmp(charSet->pNode->pData, v5) )
    {
      v5 = off_8765A0[v6++];
      if ( !v5 )
        goto LABEL_4;
    }
    Size = value->pNode->Size;
    Position = this->Position;
    pData = (const __m128i *)value->pNode->pData;
    v12 = Position + Size;
    if ( Position + Size < this->Data.Data.Size )
    {
      if ( v12 >= this->Length )
        this->Length = v12;
    }
    else
    {
      Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::Resize(this, Position + Size);
    }
    memcpy((int)&this->Data.Data.Data[this->Position], pData, Size);
    this->Position += Size;
  }
  else
  {
LABEL_4:
    v7 = Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::UTF16_Names[0];
    v8 = 0;
    if ( Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::UTF16_Names[0] )
    {
      while ( strcmp(charSet->pNode->pData, v7) )
      {
        v7 = (&off_8765B4)[v8++];
        if ( !v7 )
          goto LABEL_13;
      }
      pNode = value->pNode;
      memset(&wbuff, 0, sizeof(wbuff));
      Scaleform::WStringBuffer::SetString(&wbuff, (char *)pNode->pData, pNode->Size);
      v17 = this->Position;
      v18 = this->Data.Data.Size;
      v19 = v17 + wbuff.Length;
      Length = wbuff.Length;
      valuea = (const __m128i *)wbuff.pText;
      if ( v17 + wbuff.Length < v18 )
      {
        ID = v24.ID;
        if ( v19 >= *(_DWORD *)(v24.ID + 40) )
          *(_DWORD *)(v24.ID + 40) = v19;
      }
      else
      {
        if ( v17 + wbuff.Length > v18 )
        {
          v21 = (_DWORD *)(v24.ID + 44);
          if ( v19 >= *(_DWORD *)(v24.ID + 48) )
          {
            if ( v19 >= *(_DWORD *)(v24.ID + 52) )
              Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)(v24.ID + 44),
                (const void *)(v24.ID + 44),
                v19 + (v19 >> 2));
          }
          else if ( v19 < *(_DWORD *)(v24.ID + 52) >> 1 )
          {
            Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)(v24.ID + 44),
              (const void *)(v24.ID + 44),
              v19);
          }
          *(_DWORD *)(v24.ID + 48) = v19;
          memset(v18 + *v21, 0, v19 - v18);
        }
        ID = v24.ID;
        *(_DWORD *)(v24.ID + 40) = v19;
        if ( *(_DWORD *)(ID + 36) > v19 )
          *(_DWORD *)(ID + 36) = v19;
      }
      memcpy(*(_DWORD *)(ID + 36) + *(_DWORD *)(ID + 44), valuea, Length);
      *(_DWORD *)(ID + 36) += Length;
      Scaleform::WStringBuffer::~WStringBuffer(&wbuff);
    }
    else
    {
LABEL_13:
      pVM = this->pTraits.pObject->pVM;
      v23.pStr = "charSet";
      v23.Size = 7;
      Scaleform::GFx::AS3::VM::Error::Error(&v24, eInvalidArgumentError, pVM, v23);
      Scaleform::GFx::AS3::VM::ThrowTypeError(pVM, v14);
      v15 = v24.Message.pNode;
      --v24.Message.pNode->RefCount;
      if ( !v15->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v15);
    }
  }
}
