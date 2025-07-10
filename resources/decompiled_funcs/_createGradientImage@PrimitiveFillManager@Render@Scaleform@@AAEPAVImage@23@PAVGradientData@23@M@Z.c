Scaleform::Render::Image *__thiscall Scaleform::Render::PrimitiveFillManager::createGradientImage(
        Scaleform::Render::PrimitiveFillManager *this,
        Scaleform::Render::GradientData *data,
        float morphRatio)
{
  Scaleform::Render::GradientData *v3; // ebx
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
  Scaleform::Render::GradientKey key; // [esp+1Ch] [ebp-8h] BYREF

  v3 = data;
  key.MorphRatio = morphRatio;
  v5 = this->Gradients.pTable == 0;
  p_Gradients = &this->Gradients;
  key.pData = data;
  if ( v5
    || (v7 = Scaleform::Render::GradientData::GetHashValue(data, morphRatio),
        v8 = Scaleform::HashSetBase<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Render::GradientImage *,2>,Scaleform::HashsetCachedEntry<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor>>::findIndexCore<Scaleform::Render::GradientKey>(
               p_Gradients,
               &key,
               v7 & p_Gradients->pTable->SizeMask),
        v8 < 0) )
  {
    data = (Scaleform::Render::GradientData *)3;
    v11 = (Scaleform::Render::GradientImage *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                Scaleform::Memory::pGlobalHeap,
                                                this,
                                                40,
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
    data = *(Scaleform::Render::GradientData **)(LODWORD(v13) + 36);
    morphRatio = v13;
    HashValue = Scaleform::Render::GradientData::GetHashValue(v14, *(float *)&data);
    Scaleform::HashSetBase<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Render::GradientImage *,2>,Scaleform::HashsetCachedEntry<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor>>::add<Scaleform::Render::GradientImage *>(
      p_Gradients,
      p_Gradients,
      (Scaleform::Render::GradientImage *const *)&morphRatio,
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
