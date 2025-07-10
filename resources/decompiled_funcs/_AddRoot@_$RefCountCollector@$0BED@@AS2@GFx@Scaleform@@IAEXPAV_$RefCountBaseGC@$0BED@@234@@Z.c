void __thiscall Scaleform::GFx::AS2::RefCountCollector<323>::AddRoot(
        Scaleform::GFx::AS2::RefCountCollector<323> *this,
        Scaleform::GFx::AS2::RefCountBaseGC<323> *root)
{
  unsigned int FirstFreeRootIndex; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v4; // ecx
  Scaleform::GFx::AS2::RefCountBaseGC<323> ***Pages; // edi
  unsigned int v6; // edx
  unsigned int Size; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v8; // edi
  bool v9; // al
  char v10; // al

  FirstFreeRootIndex = this->FirstFreeRootIndex;
  if ( FirstFreeRootIndex == -1 )
  {
    Size = this->Roots.Size;
    v8 = root;
    root->RefCount |= 0x80000000;
    v8->RootIndex = Size;
    this->Flags |= 1u;
    v9 = Scaleform::ArrayPagedBase<Scaleform::GFx::AS2::RefCountBaseGC<323> *,10,5,Scaleform::AllocatorPagedLH_POD<Scaleform::GFx::AS2::RefCountBaseGC<323> *,2>>::PushBackSafe(
           &this->Roots,
           &root);
    this->Flags &= ~1u;
    if ( !v9 )
    {
      v10 = Scaleform::GFx::AS2::RefCountCollector<323>::Collect(this, 0);
      this->Flags |= 1u;
      if ( !v10
        || !Scaleform::ArrayPagedBase<Scaleform::GFx::AS2::RefCountBaseGC<323> *,10,5,Scaleform::AllocatorPagedLH_POD<Scaleform::GFx::AS2::RefCountBaseGC<323> *,2>>::PushBackSafe(
              &this->Roots,
              &root) )
      {
        v8->RefCount &= ~0x80000000;
        if ( (v8->RefCount & 0x8000000) == 0 )
          v8->RootIndex = -1;
        v8->RefCount &= 0x8FFFFFFF;
      }
      this->Flags &= ~1u;
    }
  }
  else
  {
    v4 = root;
    root->RefCount |= 0x80000000;
    v4->RootIndex = FirstFreeRootIndex;
    Pages = this->Roots.Pages;
    v6 = (int)Pages[this->FirstFreeRootIndex >> 10][this->FirstFreeRootIndex & 0x3FF] >> 1;
    Pages[this->FirstFreeRootIndex >> 10][this->FirstFreeRootIndex & 0x3FF] = v4;
    this->FirstFreeRootIndex = v6;
  }
}
