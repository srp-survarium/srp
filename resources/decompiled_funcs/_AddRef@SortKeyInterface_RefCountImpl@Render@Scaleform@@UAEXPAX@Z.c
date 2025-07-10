void __thiscall Scaleform::Render::SortKeyInterface_RefCountImpl::AddRef(
        Scaleform::Render::SortKeyInterface_RefCountImpl *this,
        Scaleform::GFx::Resource *p)
{
  if ( p )
    Scaleform::RefCountImpl::AddRef(p);
}
