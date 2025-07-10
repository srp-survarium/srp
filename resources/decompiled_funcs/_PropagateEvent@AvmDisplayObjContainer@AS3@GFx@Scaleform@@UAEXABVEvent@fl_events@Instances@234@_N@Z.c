void __thiscall Scaleform::GFx::AS3::AvmDisplayObjContainer::PropagateEvent(
        Scaleform::GFx::AS3::AvmDisplayObjContainer *this,
        const Scaleform::GFx::AS3::Instances::fl_events::Event *evtProto,
        bool inclChildren)
{
  Scaleform::GFx::DisplayObject *pDispObj; // ebx
  int v5; // esi
  Scaleform::Render::TreeNode *pObject; // edi
  int v7; // ecx
  char v8; // dl
  int v9; // eax
  int v10; // ecx

  Scaleform::GFx::AS3::AvmDisplayObj::PropagateEvent(this, evtProto, 1);
  if ( inclChildren )
  {
    pDispObj = this->pDispObj;
    if ( pDispObj[1].pRenNode.pObject )
    {
      v5 = 0;
      pObject = pDispObj[1].pRenNode.pObject;
      do
      {
        v7 = *(_DWORD *)(v5 + LODWORD(pDispObj[1].LastHitTestY));
        v8 = *(_BYTE *)(v7 + 63) & 1;
        if ( (v8 != 0 ? v7 : 0) != 0 )
        {
          v9 = v8 != 0 ? v7 : 0;
          v10 = v9 + 4 * *(unsigned __int8 *)(v9 + 65);
        }
        else
        {
          v10 = 0;
        }
        (*(void (__thiscall **)(int, const Scaleform::GFx::AS3::Instances::fl_events::Event *, int))(*(_DWORD *)v10 + 72))(
          v10,
          evtProto,
          1);
        v5 += 12;
        pObject = (Scaleform::Render::TreeNode *)((char *)pObject - 1);
      }
      while ( pObject );
    }
  }
}
