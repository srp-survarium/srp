void __usercall stlp_std::sort_heap<vostok::collision::ray_object_result *,vostok::collision::colliders::object::distance_predicate>(
        vostok::collision::ray_object_result *__first@<esi>,
        vostok::collision::ray_object_result *__last@<eax>,
        unsigned int __comp)
{
  int v3; // eax
  unsigned int v4; // ecx
  int v5; // edi
  int v6; // [esp-4h] [ebp-Ch]

  v3 = (char *)__last - (char *)__first;
  if ( (int)(v3 & 0xFFFFFFF8) > 8 )
  {
    do
    {
      v4 = *(unsigned int *)((char *)&__first[-1].object + v3);
      v6 = *(_DWORD *)((char *)__first + v3 - 4);
      *(vostok::collision::ray_object_result *)((char *)__first + v3 - 8) = *__first;
      v5 = v3 - 8;
      stlp_std::__adjust_heap<vostok::collision::ray_object_result *,int,vostok::collision::ray_object_result,vostok::collision::colliders::object::distance_predicate>(
        __first,
        0,
        (v3 - 8) >> 3,
        (vostok::collision::ray_object_result)__PAIR64__(v4, __comp),
        (vostok::collision::colliders::object::distance_predicate)v6);
      v3 = v5;
    }
    while ( (int)(v5 & 0xFFFFFFF8) > 8 );
  }
}
