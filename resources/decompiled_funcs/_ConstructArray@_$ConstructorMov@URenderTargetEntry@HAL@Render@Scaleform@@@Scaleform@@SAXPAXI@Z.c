void __cdecl Scaleform::ConstructorMov<Scaleform::Render::HAL::RenderTargetEntry>::ConstructArray(
        Scaleform::Render::HAL::RenderTargetEntry *p,
        unsigned int count)
{
  unsigned int i; // edi

  for ( i = count; i; --i )
  {
    if ( p )
      Scaleform::Render::HAL::RenderTargetEntry::RenderTargetEntry(p);
    ++p;
  }
}
