void __usercall vostok::collision::delete_animated_object(
        vostok::collision::animated_object *object_to_be_deleted@<esi>,
        vostok::memory::base_allocator *allocator)
{
  vostok::collision::animated_object *v2; // ecx
  vostok::memory::stack_allocator stack_allocator; // [esp+8h] [ebp-18h] BYREF

  memset(&stack_allocator.m_arena_start, 0, 12);
  stack_allocator.__vftable = (vostok::memory::stack_allocator_vtbl *)&vostok::memory::stack_allocator::`vftable';
  stack_allocator.m_arena_current_position = 0;
  vostok::collision::animated_object::destroy(object_to_be_deleted, &stack_allocator);
  vostok::collision::animated_object::~animated_object(v2);
  if ( object_to_be_deleted )
    allocator->call_free(allocator, object_to_be_deleted);
}
