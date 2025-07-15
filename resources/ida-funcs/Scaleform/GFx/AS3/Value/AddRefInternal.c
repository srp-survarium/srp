void __thiscall Scaleform::GFx::AS3::Value::AddRefInternal(Scaleform::GFx::AS3::Value *this)
{
  Scaleform::GFx::AS3::Value::V1U v1; // ecx
  Scaleform::GFx::AS3::Value::V2U v2; // ecx

  switch ( this->Flags & 0x1F )
  {
    case 0xAu:
      ++*(_DWORD *)(this->value.VS._1.VInt + 12);
      break;
    case 0xBu:
    case 0xCu:
    case 0xDu:
    case 0xEu:
    case 0xFu:
      v1 = this->value.VS._1;
      if ( v1.VInt )
        *(_DWORD *)(v1.VInt + 16) = (*(_DWORD *)(v1.VInt + 16) + 1) & 0x8FBFFFFF;
      break;
    case 0x10u:
    case 0x11u:
      v2.VObj = (Scaleform::GFx::AS3::Object *)this->value.VS._2;
      if ( v2.VObj )
        v2.VObj->RefCount = (v2.VObj->RefCount + 1) & 0x8FBFFFFF;
      break;
    default:
      return;
  }
}
