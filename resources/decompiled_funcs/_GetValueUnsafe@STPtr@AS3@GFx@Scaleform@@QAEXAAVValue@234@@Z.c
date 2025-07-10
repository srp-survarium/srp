void __thiscall Scaleform::GFx::AS3::STPtr::GetValueUnsafe(
        Scaleform::GFx::AS3::STPtr *this,
        Scaleform::GFx::AS3::Value *v)
{
  Scaleform::GFx::AS3::GASRefCountBase *pObject; // ecx
  Scaleform::GFx::AS3::Class *v3; // eax

  pObject = this->pObject;
  if ( pObject )
  {
    v3 = (Scaleform::GFx::AS3::Class *)((unsigned int)pObject & 0xFFFFFFF8);
    switch ( (unsigned __int8)pObject & 6 )
    {
      case 0:
        Scaleform::GFx::AS3::Value::AssignUnsafe(v, v3);
        break;
      case 2:
        Scaleform::GFx::AS3::Value::AssignUnsafe(v, v3);
        break;
      case 4:
        Scaleform::GFx::AS3::Value::AssignUnsafe(v, (Scaleform::GFx::AS3::Instances::Function *)v3);
        break;
      case 6:
        Scaleform::GFx::AS3::Value::AssignUnsafe(v, (Scaleform::GFx::AS3::Instances::fl::Namespace *)v3);
        break;
      default:
        goto LABEL_7;
    }
  }
  else
  {
LABEL_7:
    Scaleform::GFx::AS3::Value::SetNull(v);
  }
}
