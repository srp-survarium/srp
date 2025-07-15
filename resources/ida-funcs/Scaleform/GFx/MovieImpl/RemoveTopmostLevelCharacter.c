void __thiscall Scaleform::GFx::MovieImpl::RemoveTopmostLevelCharacter(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::GFx::InteractiveObject *pch)
{
  unsigned int Size; // edx
  unsigned int v3; // esi
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *Data; // eax
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::Sprite>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::Sprite>,327>,Scaleform::ArrayDefaultPolicy> *p_TopmostLevelCharacters; // edi

  Size = this->TopmostLevelCharacters.Data.Size;
  v3 = 0;
  if ( Size )
  {
    Data = this->TopmostLevelCharacters.Data.Data;
    p_TopmostLevelCharacters = (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::Sprite>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::Sprite>,327>,Scaleform::ArrayDefaultPolicy> *)&this->TopmostLevelCharacters;
    while ( Data->pObject != pch )
    {
      ++v3;
      ++Data;
      if ( v3 >= Size )
        return;
    }
    Scaleform::Render::TreeContainer::Remove(this->pTopMostRoot.pObject, v3, 1u);
    Scaleform::GFx::DisplayObjectBase::RemoveIndirectTransform(pch);
    if ( p_TopmostLevelCharacters->Size == 1 )
    {
      Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::Sprite>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::Sprite>,327>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        p_TopmostLevelCharacters,
        p_TopmostLevelCharacters,
        0);
    }
    else
    {
      if ( p_TopmostLevelCharacters->Data[v3].pObject )
        Scaleform::RefCountNTSImpl::Release(p_TopmostLevelCharacters->Data[v3].pObject);
      memmove(
        (int)&p_TopmostLevelCharacters->Data[v3],
        (const __m128i *)&p_TopmostLevelCharacters->Data[v3 + 1],
        4 * (p_TopmostLevelCharacters->Size - v3) - 4);
      --p_TopmostLevelCharacters->Size;
    }
  }
}
