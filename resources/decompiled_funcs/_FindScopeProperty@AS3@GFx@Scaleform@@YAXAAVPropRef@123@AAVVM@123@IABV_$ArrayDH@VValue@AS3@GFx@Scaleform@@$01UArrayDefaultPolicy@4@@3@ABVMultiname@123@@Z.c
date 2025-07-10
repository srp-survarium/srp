void __cdecl Scaleform::GFx::AS3::FindScopeProperty(
        Scaleform::GFx::AS3::PropRef *result,
        Scaleform::GFx::AS3::VM *vm,
        unsigned int baseSSInd,
        const Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *scope_stack,
        const Scaleform::GFx::AS3::Multiname *mn)
{
  unsigned int Size; // edi
  unsigned int v6; // esi

  Size = scope_stack->Data.Size;
  if ( Size > baseSSInd )
  {
    v6 = Size;
    do
    {
      Scaleform::GFx::AS3::FindPropertyWith(result, vm, &scope_stack->Data.Data[v6 - 1], mn, FindGet);
      if ( Scaleform::GFx::AS3::PropRef::operator bool(result) )
        break;
      --Size;
      --v6;
    }
    while ( Size > baseSSInd );
  }
}
