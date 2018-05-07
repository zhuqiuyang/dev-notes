const fastify = require('fastify')();

const opts = {
  schema: {
    response: {
      200: {
        type: 'object',
        properties: {
          hello: { type: 'string' }
        }
      }
    }
  }
};

console.log(fastify.use === fastify.register, '@@@@');

fastify.get('/', opts, function(request, reply) {
  reply.send({ hello: 'world' });
});

fastify.listen(3000, '127.0.0.1', function(err) {
  if (err) throw err;
  console.log(`server listening on ${fastify.server.address().port}`);
});
