void __thiscall Scaleform::GFx::AS3::RefCountBaseGC<328>::Release(Scaleform::GFx::AS3::RefCountBaseGC<328> *this)
{
  unsigned int RefCount; // eax

  RefCount = this->RefCount;
  if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
  {
    this->RefCount = RefCount - 1;
    Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(this);
  }
}
