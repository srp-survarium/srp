void __usercall vostok::render::scene::populate_speedtree_forest(vostok::render::scene *this@<ecx>, int a2@<eax>)
{
  vostok::render::speedtree_forest::populate_forest(
    *(vostok::render::speedtree_forest **)(a2 + 952),
    *(vostok::render::speedtree_forest **)(a2 + 952));
}
