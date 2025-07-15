void __usercall btCollisionWorld::AllHitsRayResultCallback::~AllHitsRayResultCallback(
        btCollisionWorld::AllHitsRayResultCallback *this@<ecx>,
        int a2@<edi>)
{
  btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(
    (btAlignedObjectArray<GrahamVector2> *)this,
    a2 + 160);
  JUMPOUT(0x55437);
}
