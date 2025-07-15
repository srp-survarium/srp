Scaleform::GFx::AS3::CheckResult *__cdecl Scaleform::GFx::AS3::AbstractEqual(
        Scaleform::GFx::AS3::CheckResult *result,
        bool *resulta,
        Scaleform::GFx::AS3::Value *l,
        Scaleform::GFx::AS3::Value *r)
{
  Scaleform::GFx::AS3::Value *v4; // esi
  Scaleform::GFx::AS3::Value::V1U v5; // edx
  int v6; // edi
  int v7; // eax
  Scaleform::GFx::AS3::CheckResult *v8; // eax
  int v9; // ebx
  Scaleform::GFx::AS3::Instances::fl::Namespace *VNs; // esi
  bool v11; // zf
  bool v12; // al
  Scaleform::GFx::AS3::Value::V1U v13; // edi
  int v14; // ecx
  Scaleform::GFx::AS3::Value::V1U v15; // edi
  int v16; // ecx
  bool v17; // c3
  int v18; // ecx
  int v19; // ecx
  unsigned int v20; // ecx
  Scaleform::GFx::AS3::CheckResult *v21; // esi
  Scaleform::GFx::AS3::Value::V1U v22; // [esp-6h] [ebp-40h]
  Scaleform::GFx::AS3::Value::V1U v23; // [esp-6h] [ebp-40h]
  Scaleform::GFx::AS3::Value *v24; // [esp-6h] [ebp-40h]
  Scaleform::GFx::AS3::Value *v25; // [esp-2h] [ebp-3Ch]
  bool stop; // [esp+14h] [ebp-26h] BYREF
  Scaleform::GFx::AS3::CheckResult v27; // [esp+15h] [ebp-25h] BYREF
  unsigned int v28; // [esp+16h] [ebp-24h]
  Scaleform::GFx::AS3::Value v; // [esp+1Ah] [ebp-20h] BYREF
  Scaleform::GFx::AS3::Value v30; // [esp+2Ah] [ebp-10h] BYREF

  v4 = l;
  v.Flags = l->Flags & 0x1F;
  if ( v.Flags - 12 <= 3 )
  {
    v5 = l->value.VS._1;
    if ( v5.VInt )
    {
      v6 = *(_DWORD *)(v5.VInt + 20);
      if ( *(_DWORD *)(v6 + 60) == 14 && (*(_DWORD *)(v6 + 56) & 0x20) == 0 )
      {
        v4 = r;
        v7 = *(_DWORD *)(v5.VInt + 20);
LABEL_6:
        (*(void (__thiscall **)(_DWORD, Scaleform::GFx::AS3::CheckResult *, bool *, Scaleform::GFx::AS3::Value::V1U, Scaleform::GFx::AS3::Value *))(**(_DWORD **)(*(_DWORD *)(v7 + 64) + 36) + 32))(
          *(_DWORD *)(*(_DWORD *)(v7 + 64) + 36),
          result,
          resulta,
          v5,
          v4);
        return result;
      }
    }
  }
  v28 = r->Flags & 0x1F;
  if ( v28 - 12 <= 3 )
  {
    v5 = r->value.VS._1;
    if ( v5.VInt )
    {
      v9 = *(_DWORD *)(v5.VInt + 20);
      if ( *(_DWORD *)(v9 + 60) == 14 && (*(_DWORD *)(v9 + 56) & 0x20) == 0 )
      {
        v7 = *(_DWORD *)(v5.VInt + 20);
        goto LABEL_6;
      }
    }
  }
  if ( v.Flags != v28 )
  {
    if ( !v.Flags && v28 - 12 <= 3 && !r->value.VS._1.VInt || !v28 && v.Flags - 12 <= 3 && !l->value.VS._1.VInt )
    {
      *resulta = 1;
      v8 = result;
      result->Result = 1;
      return v8;
    }
    if ( v.Flags == 4 )
    {
      if ( v28 == 10 )
      {
        if ( !Scaleform::GFx::AS3::Value::Convert2NumberInline(
                r,
                (Scaleform::GFx::AS3::CheckResult *)&stop,
                (long double *)&v.Flags)->Result )
        {
LABEL_57:
          v8 = result;
          result->Result = 0;
          return v8;
        }
        v17 = *(double *)&v.Flags == l->value.VNumber;
        goto LABEL_59;
      }
    }
    else if ( v.Flags == 10 && v28 == 4 )
    {
      if ( !Scaleform::GFx::AS3::Value::Convert2NumberInline(
              l,
              (Scaleform::GFx::AS3::CheckResult *)&stop,
              (long double *)&v.Flags)->Result )
        goto LABEL_57;
      v17 = r->value.VNumber == *(double *)&v.Flags;
LABEL_59:
      if ( !v17 )
      {
LABEL_37:
        *resulta = 0;
        v8 = result;
        result->Result = 1;
        return v8;
      }
LABEL_35:
      *resulta = 1;
      goto LABEL_36;
    }
    if ( Scaleform::GFx::AS3::IsXMLObject(l) )
    {
      v18 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(l->value.VS._1.VInt + 20) + 64) + 36);
      v22 = l->value.VS._1;
      stop = 1;
      if ( !*(_BYTE *)(*(int (__thiscall **)(int, Scaleform::GFx::AS3::CheckResult *, bool *, bool *, Scaleform::GFx::AS3::Value::V1U, Scaleform::GFx::AS3::Value *))(*(_DWORD *)v18 + 24))(
                        v18,
                        &v27,
                        &stop,
                        resulta,
                        v22,
                        r) )
        goto LABEL_57;
      if ( stop )
      {
        v8 = result;
        result->Result = 1;
        return v8;
      }
    }
    else if ( Scaleform::GFx::AS3::IsXMLObject(r) )
    {
      v19 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(r->value.VS._1.VInt + 20) + 64) + 36);
      v23 = r->value.VS._1;
      stop = 1;
      if ( !*(_BYTE *)(*(int (__thiscall **)(int, Scaleform::GFx::AS3::CheckResult *, bool *, bool *, Scaleform::GFx::AS3::Value::V1U, Scaleform::GFx::AS3::Value *))(*(_DWORD *)v19 + 24))(
                        v19,
                        &v27,
                        &stop,
                        resulta,
                        v23,
                        l) )
        goto LABEL_57;
      if ( stop )
      {
LABEL_36:
        v8 = result;
        result->Result = 1;
        return v8;
      }
    }
    if ( v.Flags )
    {
      v20 = v28;
      if ( v.Flags - 12 <= 3 && !v28 )
      {
        if ( (l->Flags & 0x1F) - 12 <= 3 )
        {
          *resulta = l->value.VS._1.VInt == v28;
          v8 = result;
          result->Result = 1;
          return v8;
        }
LABEL_76:
        *resulta = 0;
        v8 = result;
        result->Result = 1;
        return v8;
      }
      if ( (v.Flags == 10 || v.Flags == 4) && v28 - 12 <= 3 )
      {
        if ( (r->Flags & 0x1F) - 12 > 3 || r->value.VS._1.VInt )
        {
          *(_QWORD *)&v.Flags = 0;
          if ( Scaleform::GFx::AS3::Value::Convert2PrimitiveValueUnsafe(r, &v27, &v, hintNone)->Result )
          {
            v21 = result;
            Scaleform::GFx::AS3::AbstractEqual(result, resulta, l, &v);
LABEL_90:
            Scaleform::GFx::AS3::Value::~Value(&v);
            return v21;
          }
          v21 = result;
LABEL_88:
          v21->Result = 0;
          Scaleform::GFx::AS3::Value::~Value(&v);
          return v21;
        }
$LN10_93:
        v8 = result;
        *resulta = 0;
        result->Result = 1;
        return v8;
      }
    }
    else
    {
      v20 = v28;
      if ( v28 - 12 <= 3 )
      {
        if ( (r->Flags & 0x1F) - 12 <= 3 )
        {
          *resulta = r->value.VS._1.VInt == v.Flags;
          v8 = result;
          result->Result = 1;
          return v8;
        }
        goto LABEL_76;
      }
    }
    if ( v.Flags - 12 > 3 || v20 != 10 && v20 != 4 )
    {
      switch ( v.Flags )
      {
        case 5u:
        case 6u:
        case 0x10u:
        case 0x11u:
          goto $LN10_93;
        default:
          switch ( v20 )
          {
            case 5u:
            case 6u:
            case 0x10u:
            case 0x11u:
              goto $LN10_93;
            default:
              if ( v.Flags == 4 )
              {
                if ( v20 == 4 )
                  goto LABEL_36;
                if ( !Scaleform::GFx::AS3::Value::Convert2NumberInline(r, &v27, (long double *)&v.Flags)->Result )
                  goto LABEL_57;
                v25 = &v30;
                v24 = l;
              }
              else
              {
                if ( !Scaleform::GFx::AS3::Value::Convert2NumberInline(l, &v27, (long double *)&v.Flags)->Result )
                  goto LABEL_57;
                v25 = r;
                v24 = &v30;
              }
              v30.value.VNumber = *(double *)&v.Flags;
              v30.Bonus.pWeakProxy = 0;
              v30.Flags = 4;
              Scaleform::GFx::AS3::AbstractEqual(result, resulta, v24, v25);
              Scaleform::GFx::AS3::Value::~Value(&v30);
              return result;
          }
      }
    }
    if ( (l->Flags & 0x1F) - 12 > 3 || l->value.VS._1.VInt )
    {
      *(_QWORD *)&v.Flags = 0;
      v21 = result;
      if ( Scaleform::GFx::AS3::Value::Convert2PrimitiveValueUnsafe(l, &v27, &v, hintNone)->Result )
      {
        Scaleform::GFx::AS3::AbstractEqual(result, resulta, &v, r);
        goto LABEL_90;
      }
      goto LABEL_88;
    }
    goto $LN10_93;
  }
  switch ( v.Flags )
  {
    case 0u:
      v8 = result;
      *resulta = 1;
      result->Result = 1;
      return v8;
    case 1u:
      if ( l->value.VS._1.VBool )
      {
        if ( !r->value.VS._1.VBool )
          goto LABEL_29;
      }
      else if ( r->value.VS._1.VBool )
      {
LABEL_29:
        *resulta = 0;
        v8 = result;
        result->Result = 1;
        return v8;
      }
      *resulta = 1;
      v8 = result;
      result->Result = 1;
      break;
    case 2u:
    case 3u:
    case 5u:
    case 0xAu:
      *resulta = l->value.VS._1.VInt == r->value.VS._1.VInt;
      v8 = result;
      result->Result = 1;
      return v8;
    case 4u:
      *(double *)&v.Flags = l->value.VNumber;
      if ( ((int)v.Bonus.pWeakProxy & 0x7FF00000) == 0x7FF00000 && (int)v.Bonus.pWeakProxy & 0xFFFFF | v.Flags
        || (*(double *)&v.Flags = r->value.VNumber, ((int)v.Bonus.pWeakProxy & 0x7FF00000) == 0x7FF00000)
        && (int)v.Bonus.pWeakProxy & 0xFFFFF | v.Flags )
      {
        v8 = result;
        *resulta = 0;
        result->Result = 1;
      }
      else
      {
        if ( r->value.VNumber != l->value.VNumber )
          goto LABEL_21;
        v8 = result;
        *resulta = 1;
        result->Result = 1;
      }
      return v8;
    case 7u:
      if ( l->value.VS._1.VInt != r->value.VS._1.VInt )
        goto LABEL_37;
      v11 = l->value.VS._2.VObj == r->value.VS._2.VObj;
      goto LABEL_34;
    case 0xBu:
      VNs = l->value.VS._1.VNs;
      if ( VNs && r->value.VS._1.VInt )
      {
        *resulta = Scaleform::GFx::AS3::Instances::fl::Namespace::operator==(VNs, r->value.VS._1.VNs);
        v8 = result;
        result->Result = 1;
      }
      else
      {
LABEL_21:
        *resulta = 0;
        v8 = result;
        result->Result = 1;
      }
      return v8;
    case 0x10u:
    case 0x11u:
      if ( l->value.VS._2.VObj != r->value.VS._2.VObj )
        goto LABEL_37;
      v11 = l->value.VS._1.VInt == r->value.VS._1.VInt;
LABEL_34:
      if ( v11 )
        goto LABEL_35;
      goto LABEL_37;
    default:
      v12 = l->value.VS._1.VInt == r->value.VS._1.VInt;
      *resulta = v12;
      if ( v12 )
        goto LABEL_36;
      if ( Scaleform::GFx::AS3::IsXMLObject(l) && Scaleform::GFx::AS3::IsXMLObject(r) )
      {
        v13 = r->value.VS._1;
        v14 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v13.VInt + 20) + 64) + 36);
        (*(void (__thiscall **)(int, Scaleform::GFx::AS3::CheckResult *, bool *, Scaleform::GFx::AS3::Value::V1U, Scaleform::GFx::AS3::Value::V1U))(*(_DWORD *)v14 + 28))(
          v14,
          result,
          resulta,
          l->value.VS._1,
          v13);
        return result;
      }
      if ( !Scaleform::GFx::AS3::IsQNameObject(l) || !Scaleform::GFx::AS3::IsQNameObject(r) )
        goto LABEL_36;
      v15 = r->value.VS._1;
      v16 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v15.VInt + 20) + 64) + 36);
      (*(void (__thiscall **)(int, Scaleform::GFx::AS3::CheckResult *, bool *, Scaleform::GFx::AS3::Value::V1U, Scaleform::GFx::AS3::Value::V1U))(*(_DWORD *)v16 + 36))(
        v16,
        result,
        resulta,
        l->value.VS._1,
        v15);
      return result;
  }
  return v8;
}
