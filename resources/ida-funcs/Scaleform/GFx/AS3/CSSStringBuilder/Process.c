void __usercall Scaleform::GFx::AS3::CSSStringBuilder::Process(
        int a1@<ebp>,
        Scaleform::String *dest,
        Scaleform::String *pobj,
        Scaleform::GFx::ASString a4)
{
  int i; // ebx
  void (__thiscall *v5)(Scaleform::GFx::AS3::Object *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::GlobalSlotIndex); // edx
  Scaleform::GFx::ASStringNode *VObj; // eax
  Scaleform::GFx::ASStringNode *v7; // ebp
  unsigned int *p_RefCount; // esi
  int v11; // [esp+18h] [ebp-24h] BYREF
  Scaleform::GFx::AS3::Value name; // [esp+1Ch] [ebp-20h] BYREF
  Scaleform::GFx::AS3::Value value; // [esp+2Ch] [ebp-10h] BYREF

  for ( i = *(_DWORD *)(*(int (__thiscall **)(Scaleform::String *, int *, _DWORD))(pobj->HeapTypeBits + 52))(
                         pobj,
                         &v11,
                         0);
        i;
        i = *(_DWORD *)(*(int (__thiscall **)(Scaleform::String *, Scaleform::GFx::AS3::Value *))(pobj->HeapTypeBits + 52))(
                         pobj,
                         &name) )
  {
    v5 = *(void (__thiscall **)(Scaleform::GFx::AS3::Object *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::GlobalSlotIndex))(pobj->HeapTypeBits + 48);
    name.Flags = 0;
    name.Bonus.pWeakProxy = 0;
    value.Flags = 0;
    value.Bonus.pWeakProxy = 0;
    ((void (__thiscall *)(Scaleform::String *, Scaleform::GFx::AS3::Value *, int, int))v5)(pobj, &name, i, a1);
    (*(void (__thiscall **)(Scaleform::String *, Scaleform::GFx::AS3::Value::Extra *, int))(pobj->HeapTypeBits + 56))(
      pobj,
      &value.Bonus,
      i);
    if ( ((int)name.Bonus.pWeakProxy & 0x1F) == 0xA )
    {
      VObj = (Scaleform::GFx::ASStringNode *)name.value.VS._2.VObj;
      ++name.value.VS._2.VObj->pPrev;
      v7 = VObj;
      p_RefCount = &VObj->RefCount;
      a4.pNode = VObj;
      Scaleform::GFx::AS3::CSSStringBuilder::processSub(pobj, &a4, (Scaleform::GFx::AS3::Value *)&value.Bonus);
      if ( (*p_RefCount)-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v7);
    }
    if ( ((int)value.Bonus.pWeakProxy & 0x1F) > 9u )
    {
      if ( ((int)value.Bonus.pWeakProxy & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef((Scaleform::GFx::AS3::Value *)&value.Bonus);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&value.Bonus);
    }
    if ( ((int)name.Bonus.pWeakProxy & 0x1F) > 9u )
    {
      if ( ((int)name.Bonus.pWeakProxy & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef((Scaleform::GFx::AS3::Value *)&name.Bonus);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&name.Bonus);
    }
    a1 = i;
  }
}
