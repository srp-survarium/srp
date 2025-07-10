Scaleform::GFx::AS3::Value *__cdecl Scaleform::GFx::AS3::GetAbsObject(
        Scaleform::GFx::AS3::Value *result,
        unsigned int addr)
{
  Scaleform::GFx::AS3::Class *v2; // ecx
  Scaleform::GFx::AS3::Value *v3; // eax

  v2 = (Scaleform::GFx::AS3::Class *)(addr - (addr & 6));
  result->Flags = 0;
  result->Bonus.pWeakProxy = 0;
  switch ( addr & 6 )
  {
    case 0u:
      Scaleform::GFx::AS3::Value::AssignUnsafe(result, v2);
      v3 = result;
      break;
    case 2u:
      Scaleform::GFx::AS3::Value::AssignUnsafe(result, v2);
      v3 = result;
      break;
    case 4u:
      Scaleform::GFx::AS3::Value::AssignUnsafe(result, (Scaleform::GFx::AS3::Instances::Function *)v2);
      v3 = result;
      break;
    case 6u:
      Scaleform::GFx::AS3::Value::AssignUnsafe(result, (Scaleform::GFx::AS3::Instances::fl::Namespace *)v2);
      goto LABEL_6;
    default:
LABEL_6:
      v3 = result;
      break;
  }
  return v3;
}
