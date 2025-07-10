Scaleform::GFx::ResourceData *__cdecl Scaleform::GFx::SubImageResourceCreator::CreateSubImageResourceData(
        Scaleform::GFx::ResourceData *result,
        Scaleform::GFx::SubImageResourceInfo *pinfo)
{
  Scaleform::GFx::ResourceData *v2; // eax

  if ( (_S6 & 1) == 0 )
  {
    _S6 |= 1u;
    inst_1.__vftable = (Scaleform::GFx::SubImageResourceCreator_vtbl *)&Scaleform::GFx::SubImageResourceCreator::`vftable';
    atexit(Scaleform::GFx::SubImageResourceCreator::CreateSubImageResourceData_::_2_::_dynamic_atexit_destructor_for__inst__);
  }
  inst_1.AddRef(&inst_1, pinfo);
  v2 = result;
  result->hData = pinfo;
  result->pInterface = &inst_1;
  return v2;
}
