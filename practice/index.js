const express = require('express');
const fs =require('fs');
const path=require('path');

const app=express();
app.use(express.json());
app.use(express.urlencoded({extended:true}));
app.use(express.static(path.resolve('./public')));

app.set('view engine','ejs');
app.set('views',path.resolve('./views'));

const arr=['salman','ankan','miraj','julfikar','sumanta'];

app.get('/',async (req,res)=>{
    res.render('index',{
        val:arr,
    });
})

app.get('/title',(req,res)=>{
    res.end('new page open');
})

app.get('/title/:anything',(req,res)=>{
    res.end('path not found');
})

app.listen(3000);