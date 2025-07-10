void __thiscall vostok::collision::loose_oct_tree::erase(
        vostok::collision::loose_oct_tree *this,
        vostok::collision::object *object)
{
  vostok::collision::loose_oct_tree::remove_impl<vostok::collision::remove_helper>(this, object);
}
