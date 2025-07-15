Scaleform::Render::TreeNode::NodeData *__thiscall Scaleform::Render::TreeNode::NodeData::operator=(
        Scaleform::Render::TreeNode::NodeData *this,
        const Scaleform::Render::TreeNode::NodeData *__that)
{
  Scaleform::Render::TreeNode::NodeData *result; // eax
  float x2; // [esp+10h] [ebp-8h]
  float v6; // [esp+10h] [ebp-8h]
  float y2; // [esp+14h] [ebp-4h]
  float v8; // [esp+14h] [ebp-4h]
  float __thata; // [esp+1Ch] [ebp+4h]
  float __thatb; // [esp+1Ch] [ebp+4h]

  this->Type = __that->Type;
  this->Flags = __that->Flags;
  memcpy((unsigned __int8 *)&this->M34, (unsigned __int8 *)&__that->M34, sizeof(this->M34));
  if ( this->States.ArraySize | __that->States.ArraySize )
    Scaleform::Render::StateData::assignBag(&this->States, &__that->States);
  qmemcpy(&this->Cx, &__that->Cx, sizeof(this->Cx));
  __thata = __that->AproxLocalBounds.y1;
  x2 = __that->AproxLocalBounds.x2;
  y2 = __that->AproxLocalBounds.y2;
  this->AproxLocalBounds.x1 = __that->AproxLocalBounds.x1;
  this->AproxLocalBounds.y1 = __thata;
  this->AproxLocalBounds.x2 = x2;
  this->AproxLocalBounds.y2 = y2;
  result = this;
  __thatb = __that->AproxParentBounds.y1;
  v8 = __that->AproxParentBounds.x2;
  v6 = __that->AproxParentBounds.y2;
  this->AproxParentBounds.x1 = __that->AproxParentBounds.x1;
  this->AproxParentBounds.y1 = __thatb;
  this->AproxParentBounds.x2 = v8;
  this->AproxParentBounds.y2 = v6;
  return result;
}
