void __thiscall Scaleform::GFx::AS2::RefCountCollector<323>::RemoveFromRoots(
        Scaleform::GFx::AS2::RefCountCollector<323> *this,
        Scaleform::GFx::AS2::RefCountBaseGC<323> *root)
{
  if ( (root->RefCount & 0x80000000) != 0 && (root->RefCount & 0x8000000) == 0 )
  {
    if ( root->RootIndex + 1 == this->Roots.Size )
    {
      Scaleform::ArrayPagedBase<Scaleform::GFx::AS2::RefCountBaseGC<323> *,10,5,Scaleform::AllocatorPagedLH_POD<Scaleform::GFx::AS2::RefCountBaseGC<323> *,2>>::Resize(
        &this->Roots,
        root->RootIndex);
    }
    else
    {
      this->Roots.Pages[root->RootIndex >> 10][root->RootIndex & 0x3FF] = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)((2 * this->FirstFreeRootIndex) | 1);
      this->FirstFreeRootIndex = root->RootIndex;
    }
    root->RefCount &= ~0x80000000;
    if ( (root->RefCount & 0x8000000) == 0 )
      root->RootIndex = -1;
  }
}
