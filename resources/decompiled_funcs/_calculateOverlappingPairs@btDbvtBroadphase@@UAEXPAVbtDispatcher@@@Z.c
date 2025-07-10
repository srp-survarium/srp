void __thiscall btDbvtBroadphase::calculateOverlappingPairs(btDbvtBroadphase *this, btDispatcher *dispatcher)
{
  btDbvtBroadphase *v3; // ecx

  btDbvtBroadphase::collide(this, (btDbvtNode *)this, dispatcher);
  btDbvtBroadphase::performDeferredRemoval(v3, this, dispatcher);
}
