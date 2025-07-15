void __thiscall Scaleform::Render::TreeNode::NodeData::NodeData(
        Scaleform::Render::TreeNode::NodeData *this,
        const Scaleform::Render::TreeNode::NodeData *__that)
{
  float x2; // [esp+10h] [ebp-8h]
  float v5; // [esp+10h] [ebp-8h]
  float y2; // [esp+14h] [ebp-4h]
  float v7; // [esp+14h] [ebp-4h]
  float y1; // [esp+1Ch] [ebp+4h]
  float v9; // [esp+1Ch] [ebp+4h]

  this->__vftable = (Scaleform::Render::TreeNode::NodeData_vtbl *)&Scaleform::Render::ContextImpl::EntryData::`vftable';
  this->Type = __that->Type;
  this->Flags = __that->Flags;
  this->__vftable = (Scaleform::Render::TreeNode::NodeData_vtbl *)&Scaleform::Render::TreeNode::NodeData::`vftable';
  memcpy((int)&this->M34, (const __m128i *)&__that->M34, sizeof(this->M34));
  Scaleform::Render::StateBag::StateBag(&this->States, &__that->States);
  qmemcpy(&this->Cx, &__that->Cx, sizeof(this->Cx));
  y1 = __that->AproxLocalBounds.y1;
  x2 = __that->AproxLocalBounds.x2;
  y2 = __that->AproxLocalBounds.y2;
  this->AproxLocalBounds.x1 = __that->AproxLocalBounds.x1;
  this->AproxLocalBounds.y1 = y1;
  this->AproxLocalBounds.x2 = x2;
  this->AproxLocalBounds.y2 = y2;
  v9 = __that->AproxParentBounds.y1;
  v7 = __that->AproxParentBounds.x2;
  v5 = __that->AproxParentBounds.y2;
  this->AproxParentBounds.x1 = __that->AproxParentBounds.x1;
  this->AproxParentBounds.y1 = v9;
  this->AproxParentBounds.x2 = v7;
  this->AproxParentBounds.y2 = v5;
}


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
  memcpy((int)&this->M34, (const __m128i *)&src.pC->M34, sizeof(this->M34));
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


void __thiscall Scaleform::Render::TreeNode::NodeData::NodeData(
        Scaleform::Render::TreeNode::NodeData *this,
        Scaleform::Render::ContextImpl::EntryData::EntryType type)
{
  Scaleform::Render::Matrix3x4<float> *p_M34; // edi

  p_M34 = &this->M34;
  this->Type = type;
  this->Flags = 1;
  this->__vftable = (Scaleform::Render::TreeNode::NodeData_vtbl *)&Scaleform::Render::TreeNode::NodeData::`vftable';
  memset((int)&this->M34, 0, sizeof(this->M34));
  p_M34->M[0][0] = 1.0;
  this->M34.M[1][1] = 1.0;
  this->M34.M[2][2] = 1.0;
  this->States.ArraySize = 0;
  this->States.DataValue = 0;
  Scaleform::Render::Cxform::Cxform(&this->Cx);
  this->AproxLocalBounds.x1 = 0.0;
  this->AproxLocalBounds.y1 = 0.0;
  this->AproxLocalBounds.x2 = 0.0;
  this->AproxLocalBounds.y2 = 0.0;
  this->AproxParentBounds.x1 = 0.0;
  this->AproxParentBounds.y1 = 0.0;
  this->AproxParentBounds.x2 = 0.0;
  this->AproxParentBounds.y2 = 0.0;
}
