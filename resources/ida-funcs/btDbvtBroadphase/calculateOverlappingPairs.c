void __thiscall btDbvtBroadphase::calculateOverlappingPairs(btDbvtBroadphase *this, btDispatcher *dispatcher)
{
  btDbvtBroadphase *v3; // ecx

  btDbvtBroadphase::collide(this, (btDbvtNode *)this, (int)dispatcher);
  btDbvtBroadphase::performDeferredRemoval(v3, (btDispatcher *)this, (int)dispatcher);
}
