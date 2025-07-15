Scaleform::GFx::AS3::VMAbcFile *__thiscall Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_object::GetFilePtr(
        Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_object *this)
{
  const Scaleform::GFx::AS3::ClassTraits::Traits *pObject; // ecx

  pObject = this->EnclosedClassTraits.pObject;
  if ( pObject )
    return pObject->GetFilePtr(pObject);
  else
    return 0;
}
