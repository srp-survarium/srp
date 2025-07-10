void __thiscall Scaleform::Render::TreeNode::NodeData::NodeData(
        Scaleform::Render::TreeNode::NodeData *this,
        Scaleform::Render::ContextImpl::NonlocalCloneArg<Scaleform::Render::TreeNode::NodeData> src)
{
  float y1; // [esp+10h] [ebp-Ch]
  float v4; // [esp+10h] [ebp-Ch]
  float x2; // [esp+14h] [ebp-8h]
  float v6; // [esp+14h] [ebp-8h]
  float y2; // [esp+18h] [ebp-4h]
  float v8; // [esp+18h] [ebp-4h]

  this->__vftable = (Scaleform::Render::TreeNode::NodeData_vtbl *)&Scaleform::Render::ContextImpl::EntryData::`vftable';
  this->Type = src.pC->Type;
  this->Flags = src.pC->Flags & 0xFFCF;
  this->__vftable = (Scaleform::Render::TreeNode::NodeData_vtbl *)&Scaleform::Render::TreeNode::NodeData::`vftable';
  memcpy((unsigned __int8 *)&this->M34, (unsigned __int8 *)&src.pC->M34, sizeof(this->M34));
  this->States.ArraySize = 0;
  this->States.DataValue = 0;
  qmemcpy(&this->Cx, &src.pC->Cx, sizeof(this->Cx));
  y1 = src.pC->AproxLocalBounds.y1;
  x2 = src.pC->AproxLocalBounds.x2;
  y2 = src.pC->AproxLocalBounds.y2;
  this->AproxLocalBounds.x1 = src.pC->AproxLocalBounds.x1;
  this->AproxLocalBounds.y1 = y1;
  this->AproxLocalBounds.x2 = x2;
  this->AproxLocalBounds.y2 = y2;
  v8 = src.pC->AproxParentBounds.y1;
  v6 = src.pC->AproxParentBounds.x2;
  v4 = src.pC->AproxParentBounds.y2;
  this->AproxParentBounds.x1 = src.pC->AproxParentBounds.x1;
  this->AproxParentBounds.y1 = v8;
  this->AproxParentBounds.x2 = v6;
  this->AproxParentBounds.y2 = v4;
}
