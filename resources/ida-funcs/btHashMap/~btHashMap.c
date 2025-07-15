void __usercall btHashMap<btHashKey<btTriIndex>,btTriIndex>::~btHashMap<btHashKey<btTriIndex>,btTriIndex>(
        btHashMap<btHashKey<btTriIndex>,btTriIndex> *this@<ecx>,
        int a2@<edi>)
{
  btAlignedObjectArray<GrahamVector2> *v2; // ecx
  btAlignedObjectArray<GrahamVector2> *v3; // ecx
  btAlignedObjectArray<GrahamVector2> *v4; // ecx

  btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(
    (btAlignedObjectArray<GrahamVector2> *)this,
    a2 + 60);
  btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(v2, a2 + 40);
  btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(v3, a2 + 20);
  btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(v4, a2);
}
