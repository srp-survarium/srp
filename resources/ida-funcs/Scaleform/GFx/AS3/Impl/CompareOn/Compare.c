double __thiscall Scaleform::GFx::AS3::Impl::CompareOn::Compare(
        Scaleform::GFx::AS3::Impl::CompareOn *this,
        const Scaleform::GFx::AS3::Value *a,
        const Scaleform::GFx::AS3::Value *b)
{
  double v3; // st7
  unsigned int v5; // ebx
  int v6; // ebx
  bool v7; // al
  unsigned int v8; // ebx
  int v9; // ebx
  bool v10; // al
  Scaleform::GFx::ASStringManager *pStringManager; // eax
  bool v12; // cl
  unsigned int v13; // eax
  double v14; // st7
  Scaleform::GFx::ASStringNode *v15; // eax
  Scaleform::GFx::ASStringNode *v16; // eax
  unsigned int RefCount; // edx
  Scaleform::GFx::AS3::GASRefCountBase *pObject; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v20; // eax
  Scaleform::GFx::AS3::VM *Vm; // [esp-14h] [ebp-D0h]
  Scaleform::GFx::AS3::VM *v22; // [esp-10h] [ebp-CCh]
  unsigned int v23; // [esp+8h] [ebp-B4h]
  unsigned int v24; // [esp+8h] [ebp-B4h]
  double result; // [esp+Ch] [ebp-B0h]
  Scaleform::GFx::ASString str_a; // [esp+18h] [ebp-A4h] BYREF
  bool descending; // [esp+1Fh] [ebp-9Dh]
  Scaleform::GFx::ASString str_b; // [esp+20h] [ebp-9Ch] BYREF
  Scaleform::GFx::AS3::Value value_a; // [esp+24h] [ebp-98h] BYREF
  Scaleform::GFx::AS3::Value value_b; // [esp+34h] [ebp-88h] BYREF
  unsigned int i; // [esp+48h] [ebp-74h]
  Scaleform::GFx::AS3::CheckResult v32; // [esp+4Fh] [ebp-6Dh] BYREF
  unsigned int v33; // [esp+50h] [ebp-6Ch]
  Scaleform::GFx::AS3::CheckResult v34; // [esp+57h] [ebp-65h] BYREF
  Scaleform::GFx::AS3::CheckResult v35; // [esp+58h] [ebp-64h] BYREF
  Scaleform::GFx::AS3::CheckResult v36; // [esp+59h] [ebp-63h] BYREF
  Scaleform::GFx::AS3::CheckResult v37; // [esp+5Ah] [ebp-62h] BYREF
  Scaleform::GFx::AS3::CheckResult v38; // [esp+5Bh] [ebp-61h] BYREF
  Scaleform::GFx::AS3::PropRef prop_a; // [esp+5Ch] [ebp-60h] BYREF
  Scaleform::GFx::AS3::PropRef prop_b; // [esp+74h] [ebp-48h] BYREF
  unsigned int size; // [esp+8Ch] [ebp-30h]
  BOOL case_sensitive; // [esp+90h] [ebp-2Ch]
  Scaleform::GFx::AS3::Multiname name; // [esp+94h] [ebp-28h] BYREF
  double num_b; // [esp+ACh] [ebp-10h] BYREF
  double num_a; // [esp+B4h] [ebp-8h] BYREF

  v3 = 0.0;
  result = 0.0;
  v5 = 0;
  v23 = 0;
  size = this->Fields->Data.Size;
  i = 0;
  if ( size )
  {
    v33 = 0;
    while ( 1 )
    {
      if ( 0.0 != v3 )
        return v3;
      Scaleform::GFx::AS3::Multiname::Multiname(
        &name,
        this->Vm->PublicNamespace.pObject,
        &this->Fields->Data.Data[v33 / 0x10]);
      Vm = this->Vm;
      memset(&prop_a, 0, 16);
      memset(&prop_b, 0, 16);
      Scaleform::GFx::AS3::FindObjProperty(&prop_a, Vm, a, &name, FindGet);
      Scaleform::GFx::AS3::FindObjProperty(&prop_b, this->Vm, b, &name, FindGet);
      if ( (prop_a.This.Flags & 0x1F) != 0
        && (((int)prop_a.pSI & 1) == 0 || ((int)prop_a.pSI & 0xFFFFFFFE) != 0)
        && (((int)prop_a.pSI & 2) == 0 || ((int)prop_a.pSI & 0xFFFFFFFD) != 0)
        && (prop_b.This.Flags & 0x1F) != 0
        && (((int)prop_b.pSI & 1) == 0 || ((int)prop_b.pSI & 0xFFFFFFFE) != 0)
        && (((int)prop_b.pSI & 2) == 0 || ((int)prop_b.pSI & 0xFFFFFFFD) != 0) )
      {
        v22 = this->Vm;
        v6 = v5 | 1;
        value_a.Flags = 0;
        value_a.Bonus.pWeakProxy = 0;
        value_b.Flags = 0;
        value_b.Bonus.pWeakProxy = 0;
        v24 = v6;
        v7 = 1;
        if ( Scaleform::GFx::AS3::PropRef::GetSlotValueUnsafe(&prop_a, &v37, v22, &value_a, valGet)->Result )
        {
          v6 |= 2u;
          v24 = v6;
          if ( Scaleform::GFx::AS3::PropRef::GetSlotValueUnsafe(&prop_b, &v36, this->Vm, &value_b, valGet)->Result )
            v7 = 0;
        }
        if ( (v6 & 2) != 0 )
        {
          v6 &= ~2u;
          v24 = v6;
        }
        if ( (v6 & 1) != 0 )
          v24 = v6 & 0xFFFFFFFE;
        if ( v7 )
        {
          if ( (value_b.Flags & 0x1F) > 9 )
          {
            if ( (value_b.Flags & 0x200) != 0 )
              Scaleform::GFx::AS3::Value::ReleaseWeakRef(&value_b);
            else
              Scaleform::GFx::AS3::Value::ReleaseInternal(&value_b);
          }
          if ( (value_a.Flags & 0x1F) > 9 )
          {
            if ( (value_a.Flags & 0x200) != 0 )
              Scaleform::GFx::AS3::Value::ReleaseWeakRef(&value_a);
            else
              Scaleform::GFx::AS3::Value::ReleaseInternal(&value_a);
          }
          if ( (prop_b.This.Flags & 0x1F) > 9 )
          {
            if ( (prop_b.This.Flags & 0x200) != 0 )
              Scaleform::GFx::AS3::Value::ReleaseWeakRef(&prop_b.This);
            else
              Scaleform::GFx::AS3::Value::ReleaseInternal(&prop_b.This);
          }
          if ( (prop_a.This.Flags & 0x1F) > 9 )
          {
            if ( (prop_a.This.Flags & 0x200) != 0 )
              Scaleform::GFx::AS3::Value::ReleaseWeakRef(&prop_a.This);
            else
              Scaleform::GFx::AS3::Value::ReleaseInternal(&prop_a.This);
          }
          goto LABEL_110;
        }
        v8 = this->Flags->Data.Data[i];
        descending = (v8 & 2) != 0;
        if ( (v8 & 0x10) != 0 )
        {
          num_a = 0.0;
          num_b = 0.0;
          v9 = v24 | 4;
          v23 = v24 | 4;
          v10 = 1;
          if ( Scaleform::GFx::AS3::Value::Convert2Number(&value_a, &v34, &num_a)->Result )
          {
            v9 |= 8u;
            v23 = v9;
            if ( Scaleform::GFx::AS3::Value::Convert2Number(&value_b, &v35, &num_b)->Result )
              v10 = 0;
          }
          if ( (v9 & 8) != 0 )
          {
            v9 &= ~8u;
            v23 = v9;
          }
          if ( (v9 & 4) != 0 )
            v23 = v9 & 0xFFFFFFFB;
          if ( v10 )
            goto LABEL_101;
          result = num_a - num_b;
        }
        else
        {
          pStringManager = this->Vm->StringManagerRef->pStringManager;
          v23 = v24 | 0x10;
          str_a.pNode = &pStringManager->EmptyStringNode;
          ++pStringManager->EmptyStringNode.RefCount;
          str_b.pNode = str_a.pNode;
          ++str_a.pNode->RefCount;
          v12 = 1;
          if ( Scaleform::GFx::AS3::Value::Convert2String(&value_a, &v32, &str_a)->Result )
          {
            v23 |= 0x20u;
            if ( Scaleform::GFx::AS3::Value::Convert2String(&value_b, &v38, &str_b)->Result )
              v12 = 0;
          }
          v13 = v23;
          if ( (v23 & 0x20) != 0 )
          {
            v13 = v23 & 0xFFFFFFDF;
            v23 &= ~0x20u;
          }
          if ( (v13 & 0x10) != 0 )
            v23 = v13 & 0xFFFFFFEF;
          if ( v12 )
          {
            pNode = str_b.pNode;
            --str_b.pNode->RefCount;
            if ( !pNode->RefCount )
              Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
            v20 = str_a.pNode;
            --str_a.pNode->RefCount;
            if ( !v20->RefCount )
              Scaleform::GFx::ASStringNode::ReleaseNode(v20);
LABEL_101:
            if ( (value_b.Flags & 0x1F) > 9 )
            {
              if ( (value_b.Flags & 0x200) != 0 )
                Scaleform::GFx::AS3::Value::ReleaseWeakRef(&value_b);
              else
                Scaleform::GFx::AS3::Value::ReleaseInternal(&value_b);
            }
            if ( (value_a.Flags & 0x1F) > 9 )
            {
              if ( (value_a.Flags & 0x200) != 0 )
                Scaleform::GFx::AS3::Value::ReleaseWeakRef(&value_a);
              else
                Scaleform::GFx::AS3::Value::ReleaseInternal(&value_a);
            }
            Scaleform::GFx::AS3::PropRef::~PropRef(&prop_b);
            Scaleform::GFx::AS3::PropRef::~PropRef(&prop_a);
LABEL_110:
            Scaleform::GFx::AS3::Multiname::~Multiname(&name);
            return result;
          }
          LOBYTE(case_sensitive) = (v8 & 1) == 0;
          if ( (v8 & 0x400) != 0 )
          {
            v14 = (double)Scaleform::GFx::ASString::LocaleCompare_CaseCheck(&str_a, &str_b, case_sensitive);
          }
          else if ( (v8 & 1) != 0 )
          {
            v14 = (double)Scaleform::String::CompareNoCase((char *)str_a.pNode->pData, (char *)str_b.pNode->pData);
          }
          else
          {
            v14 = (double)Scaleform::SFstrcmp(str_a.pNode->pData, str_b.pNode->pData);
          }
          v15 = str_b.pNode;
          result = v14;
          --str_b.pNode->RefCount;
          if ( !v15->RefCount )
            Scaleform::GFx::ASStringNode::ReleaseNode(v15);
          v16 = str_a.pNode;
          --str_a.pNode->RefCount;
          if ( !v16->RefCount )
            Scaleform::GFx::ASStringNode::ReleaseNode(v16);
        }
        if ( descending )
          result = -result;
        if ( (value_b.Flags & 0x1F) > 9 )
        {
          if ( (value_b.Flags & 0x200) != 0 )
            Scaleform::GFx::AS3::Value::ReleaseWeakRef(&value_b);
          else
            Scaleform::GFx::AS3::Value::ReleaseInternal(&value_b);
        }
        if ( (value_a.Flags & 0x1F) > 9 )
        {
          if ( (value_a.Flags & 0x200) != 0 )
            Scaleform::GFx::AS3::Value::ReleaseWeakRef(&value_a);
          else
            Scaleform::GFx::AS3::Value::ReleaseInternal(&value_a);
        }
      }
      if ( (prop_b.This.Flags & 0x1F) > 9 )
      {
        if ( (prop_b.This.Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&prop_b.This);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&prop_b.This);
      }
      if ( (prop_a.This.Flags & 0x1F) > 9 )
      {
        if ( (prop_a.This.Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&prop_a.This);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&prop_a.This);
      }
      if ( (name.Name.Flags & 0x1F) > 9 )
      {
        if ( (name.Name.Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&name.Name);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&name.Name);
      }
      if ( name.Obj.pObject && ((int)name.Obj.pObject & 1) == 0 )
      {
        RefCount = name.Obj.pObject->RefCount;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          pObject = name.Obj.pObject;
          name.Obj.pObject->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
        }
      }
      v3 = result;
      v33 += 16;
      if ( ++i >= size )
        return v3;
      v5 = v23;
    }
  }
  return v3;
}
