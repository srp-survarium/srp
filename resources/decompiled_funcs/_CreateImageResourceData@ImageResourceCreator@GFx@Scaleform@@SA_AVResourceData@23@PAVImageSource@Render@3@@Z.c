Scaleform::GFx::ResourceData *__cdecl Scaleform::GFx::ImageResourceCreator::CreateImageResourceData(
        Scaleform::GFx::ResourceData *result,
        Scaleform::Render::ImageSource *pimage)
{
  Scaleform::GFx::ResourceData *v2; // eax

  if ( (_S5_0 & 1) == 0 )
  {
    _S5_0 |= 1u;
    inst_0.__vftable = (Scaleform::GFx::ImageResourceCreator_vtbl *)&Scaleform::GFx::ImageResourceCreator::`vftable';
    atexit(Scaleform::GFx::ImageResourceCreator::CreateImageResourceData_::_2_::_dynamic_atexit_destructor_for__inst__);
  }
  if ( pimage )
  {
    inst_0.AddRef(&inst_0, pimage);
    v2 = result;
    result->hData = pimage;
    result->pInterface = &inst_0;
  }
  else
  {
    v2 = result;
    result->pInterface = 0;
    result->hData = 0;
  }
  return v2;
}
