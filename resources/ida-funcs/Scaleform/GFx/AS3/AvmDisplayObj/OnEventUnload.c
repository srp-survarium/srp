void __thiscall Scaleform::GFx::AS3::AvmDisplayObj::OnEventUnload(Scaleform::GFx::AS3::AvmDisplayObj *this)
{
  Scaleform::GFx::DisplayObject *pDispObj; // eax
  Scaleform::GFx::AS3::AvmInteractiveObj *AvmParent; // ebp
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *pAS3RawPtr; // eax
  int *v5; // edi
  int v6; // ebx
  int v7; // eax
  Scaleform::GFx::AS3::VM *v8; // ecx
  Scaleform::GFx::DisplayObject *v9; // eax
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *pObject; // eax
  void (__thiscall *GenerateTouchEvents)(Scaleform::GFx::ASMovieRootBase *, unsigned int); // ebp
  int v12; // ebx
  int v13; // eax
  Scaleform::GFx::AS3::VM *v14; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  const Scaleform::GFx::AS3::Value *Null; // [esp+0h] [ebp-58h]
  char v17; // [esp+17h] [ebp-41h] BYREF
  Scaleform::GFx::ASString result; // [esp+18h] [ebp-40h] BYREF
  Scaleform::GFx::AS3::AvmDisplayObj *p; // [esp+1Ch] [ebp-3Ch]
  Scaleform::GFx::AS3::Value v; // [esp+20h] [ebp-38h] BYREF
  Scaleform::GFx::AS3::Value name; // [esp+30h] [ebp-28h] BYREF
  Scaleform::GFx::AS3::Multiname v22; // [esp+40h] [ebp-18h] BYREF

  pDispObj = this->pDispObj;
  if ( pDispObj->Depth >= -1 )
  {
    if ( (pDispObj->Flags & 2) != 0
      || (pDispObj->Flags & 1) == 0
      || !Scaleform::GFx::AS3::AvmDisplayObj::GetAS3Parent(this) )
    {
      goto LABEL_24;
    }
    AvmParent = Scaleform::GFx::AS3::AvmDisplayObj::GetAvmParent(this);
    pAS3RawPtr = AvmParent->pAS3RawPtr;
    p = AvmParent;
    if ( !pAS3RawPtr )
      pAS3RawPtr = AvmParent->pAS3CollectiblePtr.pObject;
    if ( ((unsigned __int8)pAS3RawPtr & 1) != 0 )
      pAS3RawPtr = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)pAS3RawPtr - 1);
    v5 = (int *)pAS3RawPtr;
    if ( ((unsigned __int8)pAS3RawPtr & 1) != 0 )
      v5 = (int *)((char *)&pAS3RawPtr[-1].pReleaseProxy.pObject + 3);
    Scaleform::GFx::DisplayObject::GetName(this->pDispObj, &result);
    v.Flags = 0;
    v.Bonus.pWeakProxy = 0;
    Scaleform::GFx::AS3::Value::Value(&name, &result);
    v6 = *v5;
    Scaleform::GFx::AS3::Multiname::Multiname(
      &v22,
      (Scaleform::GFx::AS3::Instances::fl::Namespace *)this->pDispObj->pASRoot[2].__vftable[1].GenerateTouchEvents,
      &name);
    (*(void (__thiscall **)(int *, char *, int, Scaleform::GFx::AS3::Value *))(v6 + 28))(v5, &v17, v7, &v);
    Scaleform::GFx::AS3::Multiname::~Multiname(&v22);
    Scaleform::GFx::AS3::Value::~Value(&name);
    v8 = (Scaleform::GFx::AS3::VM *)this->pDispObj->pASRoot[2].__vftable;
    if ( v8->HandleException )
    {
      Scaleform::GFx::AS3::VM::OutputAndIgnoreException(v8);
      v9 = AvmParent->pDispObj;
    }
    else
    {
      if ( (v.Flags & 0x1F) - 12 > 3 )
        goto LABEL_22;
      pObject = this->pAS3RawPtr;
      if ( !pObject )
        pObject = this->pAS3CollectiblePtr.pObject;
      if ( ((unsigned __int8)pObject & 1) != 0 )
        pObject = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)pObject - 1);
      if ( (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)v.value.VS._1.VInt != pObject )
        goto LABEL_22;
      Scaleform::GFx::AS3::Value::Value(&name, &result);
      GenerateTouchEvents = this->pDispObj->pASRoot[2].__vftable[1].GenerateTouchEvents;
      v12 = *v5;
      Null = Scaleform::GFx::AS3::Value::GetNull();
      Scaleform::GFx::AS3::Multiname::Multiname(
        &v22,
        (Scaleform::GFx::AS3::Instances::fl::Namespace *)GenerateTouchEvents,
        &name);
      (*(void (__thiscall **)(int *, char *, int, const Scaleform::GFx::AS3::Value *))(v12 + 24))(v5, &v17, v13, Null);
      Scaleform::GFx::AS3::Multiname::~Multiname(&v22);
      Scaleform::GFx::AS3::Value::~Value(&name);
      v14 = (Scaleform::GFx::AS3::VM *)this->pDispObj->pASRoot[2].__vftable;
      if ( !v14->HandleException )
        goto LABEL_22;
      Scaleform::GFx::AS3::VM::OutputAndIgnoreException(v14);
      v9 = p->pDispObj;
    }
    v9->Flags |= 0x20u;
LABEL_22:
    Scaleform::GFx::AS3::Value::~Value(&v);
    pNode = result.pNode;
    --result.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
LABEL_24:
    Scaleform::GFx::AS3::AvmDisplayObj::OnDetachFromTimeline(this);
    return;
  }
  if ( (pDispObj->Scaleform::GFx::DisplayObjectBase::Flags & 0x10) != 0 )
    pDispObj->pParent = 0;
  this->pDispObj->Flags &= 0xEFEFu;
}
