void __thiscall Scaleform::GFx::AS2::RefCountBaseGC<323>::Release(Scaleform::GFx::AS2::RefCountBaseGC<323> *this)
{
  unsigned int RefCount; // eax

  RefCount = this->RefCount;
  if ( (RefCount & 0x3FFFFFF) != 0 )
  {
    this->RefCount = RefCount - 1;
    Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(this);
  }
}
