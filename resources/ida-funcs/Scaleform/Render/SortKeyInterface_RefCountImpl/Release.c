void __thiscall Scaleform::Render::SortKeyInterface_RefCountImpl::Release(
        Scaleform::Render::SortKeyInterface_RefCountImpl *this,
        Scaleform::RefCountVImpl *p)
{
  if ( p )
    Scaleform::RefCountImpl::Release(p);
}
