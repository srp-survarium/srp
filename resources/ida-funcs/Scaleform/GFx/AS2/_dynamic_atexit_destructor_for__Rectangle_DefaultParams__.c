void __cdecl Scaleform::GFx::AS2::_dynamic_atexit_destructor_for__Rectangle_DefaultParams__()
{
  Scaleform::GFx::AS2::Value *v0; // esi
  int i; // edi

  v0 = (Scaleform::GFx::AS2::Value *)GAS_StringFunctionTable;
  for ( i = 3; i >= 0; --i )
  {
    --v0;
    if ( v0->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v0);
  }
}
