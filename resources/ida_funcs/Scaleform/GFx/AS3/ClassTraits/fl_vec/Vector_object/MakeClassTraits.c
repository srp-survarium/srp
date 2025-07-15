Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__cdecl Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_object::MakeClassTraits(
        Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result,
        Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::GFx::AS3::ClassTraits::Traits *v2; // eax
  Scaleform::GFx::AS3::ClassTraits::Traits *v3; // esi
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v4; // eax

  v2 = (Scaleform::GFx::AS3::ClassTraits::Traits *)vm->MHeap->Alloc(vm->MHeap, 108, 0);
  v3 = v2;
  if ( v2 )
  {
    Scaleform::GFx::AS3::ClassTraits::Traits::Traits(
      v2,
      vm,
      (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl_vec::Vector_objectCI);
    v4 = result;
    v3->__vftable = (Scaleform::GFx::AS3::ClassTraits::Traits_vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_object::`vftable';
    v3[1].__vftable = 0;
    v3->TraitsType = Traits_Vector_object;
    result->pV = v3;
  }
  else
  {
    v4 = result;
    result->pV = 0;
  }
  return v4;
}
