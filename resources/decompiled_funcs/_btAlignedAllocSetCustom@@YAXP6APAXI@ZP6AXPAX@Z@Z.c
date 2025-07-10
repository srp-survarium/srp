void __cdecl btAlignedAllocSetCustom()
{
  sAllocFunc = bullet_alloc;
  if ( !bullet_alloc )
    sAllocFunc = btAllocDefault;
  sFreeFunc = bullet_free;
  if ( !bullet_free )
    sFreeFunc = btFreeDefault;
}
