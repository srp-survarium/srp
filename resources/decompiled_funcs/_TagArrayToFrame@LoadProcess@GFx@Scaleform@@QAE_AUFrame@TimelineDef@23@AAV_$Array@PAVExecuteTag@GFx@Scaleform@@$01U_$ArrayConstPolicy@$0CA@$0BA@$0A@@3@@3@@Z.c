Scaleform::GFx::TimelineDef::Frame *__thiscall Scaleform::GFx::LoadProcess::TagArrayToFrame(
        Scaleform::GFx::LoadProcess *this,
        Scaleform::GFx::TimelineDef::Frame *result,
        Scaleform::Array<Scaleform::GFx::ExecuteTag *,2,Scaleform::ArrayConstPolicy<32,16,0> > *tagArray)
{
  unsigned int Size; // eax
  Scaleform::GFx::TimelineDef::Frame *v4; // edi
  Scaleform::GFx::MovieDataDef::LoadTaskData *pObject; // ecx
  unsigned int BytesLeft; // edx
  unsigned int v7; // ebx
  Scaleform::GFx::DataAllocator *p_TagMemAllocator; // ecx
  unsigned int v9; // eax
  unsigned __int8 *pCurrent; // edi
  unsigned int v11; // edx
  unsigned __int8 *v12; // eax

  Size = tagArray->Data.Size;
  v4 = result;
  result->pTagPtrList = 0;
  result->TagCount = 0;
  if ( Size )
  {
    pObject = this->pLoadData.pObject;
    BytesLeft = pObject->TagMemAllocator.BytesLeft;
    v7 = 4 * Size;
    p_TagMemAllocator = &pObject->TagMemAllocator;
    v9 = (4 * Size + 3) & 0xFFFFFFFC;
    if ( v9 > BytesLeft )
    {
      v12 = Scaleform::GFx::DataAllocator::OverflowAlloc(p_TagMemAllocator, v9);
    }
    else
    {
      pCurrent = p_TagMemAllocator->pCurrent;
      v11 = BytesLeft - v9;
      p_TagMemAllocator->pCurrent += v9;
      v12 = pCurrent;
      v4 = result;
      p_TagMemAllocator->BytesLeft = v11;
    }
    v4->pTagPtrList = (Scaleform::GFx::ExecuteTag **)v12;
    if ( v12 )
    {
      memcpy(v12, (unsigned __int8 *)tagArray->Data.Data, v7);
      v4->TagCount = tagArray->Data.Size;
    }
    if ( tagArray->Data.Size )
    {
      if ( (tagArray->Data.Policy.Capacity & 0xFFFFFFFE) != 0 )
        goto LABEL_11;
    }
    else if ( !tagArray->Data.Policy.Capacity )
    {
LABEL_11:
      Scaleform::ArrayDataBase<Scaleform::GFx::ExecuteTag *,Scaleform::AllocatorGH<Scaleform::GFx::ExecuteTag *,2>,Scaleform::ArrayConstPolicy<32,16,0>>::Reserve(
        &tagArray->Data,
        tagArray,
        0);
    }
    tagArray->Data.Size = 0;
  }
  return v4;
}
