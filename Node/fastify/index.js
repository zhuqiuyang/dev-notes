const fastify = require('fastify')();

const opts1 = {
  response: {
    200: {
      type: 'object',
      properties: {
        hello: { type: 'string' }
      }
    }
  }
};

const opts2 = {
  schema: {
    body: {
      type: 'object',
      properties: {
        someKey: { type: 'string' },
        someOtherKey: { type: 'number' }
      }
    },
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

fastify.get('/', opts1, function(request, reply) {
  reply.send({ hello: 'world' });
});

fastify.post('/test', function(request, reply) {
  console.log('@@body : ', request.body);
  reply.send({ hello: 'world' });
});

fastify.listen(3000, '127.0.0.1', function(err) {
  if (err) throw err;
  console.log(`server listening on ${fastify.server.address().port}`);
});
