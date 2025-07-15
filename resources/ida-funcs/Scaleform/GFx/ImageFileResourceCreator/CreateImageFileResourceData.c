Scaleform::GFx::ResourceData *__cdecl Scaleform::GFx::ImageFileResourceCreator::CreateImageFileResourceData(
        Scaleform::GFx::ResourceData *result,
        Scaleform::GFx::ImageFileInfo *prfi)
{
  Scaleform::GFx::ResourceData *v2; // eax

  if ( (_S4_1 & 1) == 0 )
  {
    _S4_1 |= 1u;
    inst.__vftable = (Scaleform::GFx::ImageFileResourceCreator_vtbl *)&Scaleform::GFx::ImageFileResourceCreator::`vftable';
    atexit(Scaleform::GFx::ImageFileResourceCreator::CreateImageFileResourceData_::_2_::_dynamic_atexit_destructor_for__inst__);
  }
  inst.AddRef(&inst, prfi);
  v2 = result;
  result->hData = prfi;
  result->pInterface = &inst;
  return v2;
}
