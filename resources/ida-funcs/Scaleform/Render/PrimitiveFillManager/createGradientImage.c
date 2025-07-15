Scaleform::Render::Image *__thiscall Scaleform::Render::PrimitiveFillManager::createGradientImage(
        Scaleform::Render::PrimitiveFillManager *this,
        int data,
        float morphRatio)
{
  Scaleform::GFx::Resource *v3; // ebx
  bool v5; // zf
  Scaleform::HashSetLH<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::Render::GradientImage::PtrHashFunctor,2,Scaleform::HashsetCachedEntry<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor> > *p_Gradients; // esi
  unsigned int v7; // eax
  signed int v8; // eax
  int v9; // esi
  Scaleform::Render::GradientImage *v11; // eax
  float v12; // eax
  float v13; // edi
  Scaleform::Render::GradientData *v14; // ecx
  unsigned int HashValue; // eax
  Scaleform::Render::GradientKey v16; // [esp+1Ch] [ebp-8h] BYREF

  v3 = (Scaleform::GFx::Resource *)data;
  v16.MorphRatio = morphRatio;
  v5 = this->Gradients.pTable == 0;
  p_Gradients = &this->Gradients;
  v16.pData = (const Scaleform::Render::GradientData *)data;
  if ( v5
    || (v7 = Scaleform::Render::GradientData::GetHashValue((Scaleform::Render::GradientData *)data, morphRatio),
        v8 = Scaleform::HashSetBase<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Render::GradientImage *,2>,Scaleform::HashsetCachedEntry<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor>>::findIndexCore<Scaleform::Render::GradientKey>(
               p_Gradients,
               &v16,
               v7 & p_Gradients->pTable->SizeMask),
        v8 < 0) )
  {
    data = 3;
    v11 = (Scaleform::Render::GradientImage *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                Scaleform::Memory::pGlobalHeap,
                                                this,
                                                44,
                                                &data);
    if ( v11 )
    {
      Scaleform::Render::GradientImage::GradientImage(v11, this, v3, morphRatio);
      v13 = v12;
    }
    else
    {
      v13 = 0.0;
    }
    v14 = *(Scaleform::Render::GradientData **)(LODWORD(v13) + 24);
    data = *(int *)(LODWORD(v13) + 36);
    morphRatio = v13;
    HashValue = Scaleform::Render::GradientData::GetHashValue(v14, *(float *)&data);
    Scaleform::HashSetBase<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Render::GradientImage *,2>,Scaleform::HashsetCachedEntry<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor>>::add<Scaleform::Render::GradientImage *>(
      p_Gradients,
      p_Gradients,
      (Scaleform::Render::GradientImage **)&morphRatio,
      HashValue);
    return (Scaleform::Render::Image *)LODWORD(v13);
  }
  else
  {
    v9 = *(&p_Gradients->pTable[2].EntryCount + 3 * v8);
    (*(void (__thiscall **)(int))(*(_DWORD *)v9 + 4))(v9);
    return (Scaleform::Render::Image *)v9;
  }
}
