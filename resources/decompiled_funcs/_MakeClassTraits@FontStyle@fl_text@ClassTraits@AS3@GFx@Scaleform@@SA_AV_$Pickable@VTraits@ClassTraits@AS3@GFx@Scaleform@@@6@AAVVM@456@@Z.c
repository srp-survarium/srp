Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__cdecl Scaleform::GFx::AS3::ClassTraits::fl_text::FontStyle::MakeClassTraits(
        Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result,
        Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::GFx::AS3::ClassTraits::fl_text::FontStyle *v2; // eax
  Scaleform::GFx::AS3::ClassTraits::Traits *v3; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v4; // eax

  v2 = (Scaleform::GFx::AS3::ClassTraits::fl_text::FontStyle *)vm->MHeap->Alloc(vm->MHeap, 104, 0);
  if ( v2 )
  {
    Scaleform::GFx::AS3::ClassTraits::fl_text::FontStyle::FontStyle(v2, vm);
    result->pV = v3;
    return result;
  }
  else
  {
    v4 = result;
    result->pV = 0;
  }
  return v4;
}
