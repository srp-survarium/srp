void __userpurge vostok::render::grass_world::add_grass_layer(
        bool populate@<cl>,
        bool from_cook@<al>,
        vostok::render::grass_world *this,
        vostok::render::grass_layer_desc *desc,
        vostok::render::grass_layer_data *data)
{
  vostok::render::grass_world::update_grass_layer((unsigned int)data, this, desc, 1, populate, from_cook);
}
