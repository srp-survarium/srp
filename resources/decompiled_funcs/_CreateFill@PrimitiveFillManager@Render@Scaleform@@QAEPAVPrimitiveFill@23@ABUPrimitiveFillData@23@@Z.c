Scaleform::Render::PrimitiveFill *__thiscall Scaleform::Render::PrimitiveFillManager::CreateFill(
        Scaleform::Render::PrimitiveFillManager *this,
        const Scaleform::Render::PrimitiveFillData *initdata)
{
  Scaleform::HashSetLH<Scaleform::Render::PrimitiveFill *,Scaleform::Render::PrimitiveFill::PtrHashFunctor,Scaleform::Render::PrimitiveFill::PtrHashFunctor,2,Scaleform::HashsetCachedEntry<Scaleform::Render::PrimitiveFill *,Scaleform::Render::PrimitiveFill::PtrHashFunctor> > *p_FillSet; // ebx
  Scaleform::Render::PrimitiveFill *v4; // esi
  Scaleform::Render::PrimitiveFill *result; // eax
  Scaleform::Render::PrimitiveFill *v6; // esi
  Scaleform::Render::PrimitiveFill *fill; // [esp+Ch] [ebp-4h] BYREF

  p_FillSet = &this->FillSet;
  fill = 0;
  if ( Scaleform::HashSetBase<Scaleform::Render::PrimitiveFill *,Scaleform::Render::PrimitiveFill::PtrHashFunctor,Scaleform::Render::PrimitiveFill::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Render::PrimitiveFill *,2>,Scaleform::HashsetCachedEntry<Scaleform::Render::PrimitiveFill *,Scaleform::Render::PrimitiveFill::PtrHashFunctor>>::GetAlt<Scaleform::Render::PrimitiveFillData>(
         &this->FillSet,
         initdata,
         &fill) )
  {
    v4 = fill;
    ++fill->RefCount;
    return v4;
  }
  else
  {
    result = this->pHAL->CreatePrimitiveFill(this->pHAL, initdata);
    v6 = result;
    fill = result;
    if ( result )
    {
      Scaleform::HashSet<Scaleform::Render::PrimitiveFill *,Scaleform::Render::PrimitiveFill::PtrHashFunctor,Scaleform::Render::PrimitiveFill::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Render::PrimitiveFill *,2>,Scaleform::HashsetCachedEntry<Scaleform::Render::PrimitiveFill *,Scaleform::Render::PrimitiveFill::PtrHashFunctor>>::Add<Scaleform::Render::PrimitiveFill *>(
        p_FillSet,
        &fill);
      v6->pManager = this;
      return v6;
    }
  }
  return result;
}
